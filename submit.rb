#! /usr/bin/ruby

require 'net/http'
require 'uri'

class AOJResultPrinter

  RETRY_COUNT = 5

  def self.print_result(http, path, username)
    wait_time = 2
    RETRY_COUNT.times {
      sleep(wait_time)
      response = http.get(path)
      result, need_retry = parse_result(response.body, username)
      puts result
      if(!need_retry)
        break
      end
      wait_time += 1
    }
  end
  
  def self.parse_result(text, submitter_username)
    str = text.gsub(/\s/, " ")
    submission_regexp = /<status>(.*?<status>.*?<\/status>.*?)<\/status>/
    str.scan(submission_regexp){ |matches|
      match = matches[0]

      id       = extract(match, "run_id").to_i
      username = extract(match, "user_id")
      problem  = extract(match, "problem_id")
      time     = Time.at(extract(match, "submission_date").to_i / 1000)
      status   = extract(match, "status")
      language = extract(match, "language")
      runtime  = extract(match, "cpu_time").to_i
      memory   = extract(match, "memory").to_i
      length   = extract(match, "code_size").to_i
      
      if(username == submitter_username && Time.now < time + 60)
        tokens = []
        tokens.push('')
        tokens.push("Result:      " + status)
        tokens.push("Run ID:      " + id.to_s)
        if(status != "Runtime Error" && status != "Compile Error")
          tokens.push("Time:        " + sprintf("%.02f sec", runtime.to_f/100))
          tokens.push("Memory:      " + memory.to_s + " KB")
        end
        tokens.push("Code Length: " + length.to_s + " bytes")
        return [tokens.join("\n"), false]
      end
    }
    return ["in judge queue...", true]
  end
  
  def self.extract(text, target)
    return text.scan(/<#{target}>(.*?)<\/#{target}>/)[0][0].strip
  end
end

class Submitter
  
  MAP_EXTNAME_LANGUAGE = {
    '.c'    => :c,
    '.cpp'  => :cpp,
    '.cc'   => :cpp,
    '.C'    => :cpp,
    '.java' => :java,
  }

  JUDGE_SETTING = {
    
    :aoj => {
      :name => "Aizu Online Judge",
      
      :uri         => 'rose.u-aizu.ac.jp',
      :path_submit => '/onlinejudge/servlet/Submit',
      :path_result => '/onlinejudge/webservice/status_log',

      :map_form_name => {
        :username  => 'userID',
        :password  => 'password',
        :problemID => 'problemNO',
        :language  => 'language',
        :program   => 'sourceCode'
      },

      :map_form_value_language => {
        :c    => 'C',
        :cpp  => 'C++',
        :java => 'JAVA',
      },

      :result_printer => AOJResultPrinter,
    }
  }
  
  USER_SETTING = {
    :aoj => {
      :username => 'grrifon_zero',  # <= PUT YOUR USERNAME HERE
      :password => 'mega3118',  # <= PUT YOUR PASSWORD HERE
    },
  }

  def main()
    set_params()
    submit()
  end
  
  def set_params()
    @filename  = nil
    @judge     = nil

    while(!ARGV.empty? && ARGV.first[0..0] == '-')
      option   = ARGV[0].dup
      argument = ARGV[1].dup
      ARGV.shift()
      ARGV.shift()

      if(!(option && argument))
        raise "Invalid option specified."
      end

      case(option)
      when '-judge', '-j'
        @judge     = argument.downcase.intern
      when '-problemID', '-p'
        @problemID = argument
      when '-language', '-lang', '-l'
        @language  = argument.downcase.intern
      else
        raise "Option '#{option}' is not defined."
      end
    end

    raise "Judge is not specified."     unless @judge
    raise "Filename is not specified."  unless ARGV[0]
    
    @filename = ARGV[0]
    @language  = get_language(@filename)  unless @language
    @problemID = get_problemID(@filename) unless @problemID
  end

  def get_language(filename)
    return MAP_EXTNAME_LANGUAGE[File.extname(filename)]
  end

  def get_problemID(filename)
    return File.basename(filename).split(/[^A-Z0-9]/).first
  end

  def submit()
    judge        = JUDGE_SETTING[@judge]
    uri          = judge[:uri]
    path_submit  = judge[:path_submit]
    path_result  = judge[:path_result]
    data         = create_data()
    
    print_log()

    # --------

    Net::HTTP.start(uri) { |http|
      # dryrun
      if(true)
        response = http.post(path_submit, data)
        print response.code, ' ', response.message, "\n" 
      else
        puts "Dryrun..."
      end
      
      resp = judge[:result_printer]
      
      if(path_result && judge[:result_printer])
        judge[:result_printer].print_result(http, path_result, USER_SETTING[@judge][:username])
      end
    }
  end

  def print_log()
    STDERR << "Submitting...\n"

    STDERR << "Judge:    " << JUDGE_SETTING[@judge][:name] << "\n"
    STDERR << "Problem:  " << @problemID << "\n"
    STDERR << "Language: " << @language.to_s.capitalize << "\n"
    STDERR << "Filename: " << @filename << "\n"    
  end

  def create_data()    
    judge = JUDGE_SETTING[@judge]
    user  = USER_SETTING[@judge]
    
    params = {
      :username => user[:username],
      :password => user[:password],
      
      :problemID => @problemID,
      :program   => File.open(@filename).read(),
      :language  => judge[:map_form_value_language][@language],
    }

    form_name = judge[:map_form_name]

    return params.map{ |key, value|
      enc(form_name[key]) + '=' + enc(value)
    }.join('&')
  end

  def enc(str)
    return URI.encode(str, /./n)
  end
end

Submitter.new.main()

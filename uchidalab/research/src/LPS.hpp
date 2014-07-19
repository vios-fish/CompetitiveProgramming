#ifndef LPS_HPP
#define LPS_HPP

#include <string>
#include <vector>
#include <tuple>

typedef struct glp_prob glpprob;

namespace lps{
    struct wSmcp;

    class LPS{
    public:
        enum class OptDirectFlag : int;
        enum class TypeOfSrtucturalVariable : int;
        enum class KindOfStructuralVariable : int;
        enum class StatusOfStrucuralVariable : int;
        enum class ScalingOption : int;
        enum class SolutionIndicator : int;
        enum class SolutionStatus : int;
        enum class Permition : bool;

        // simplex method control parameters
        enum class SMMsgLevel : char;
        enum class SMOption : char;
        enum class SMPrincingTec : char;
        enum class SMRatioTestTec : char;
        enum class SMResult : int;
        
        LPS();
        ~LPS();

        void setProbName(const std::string &name);
        void setObjName(const std::string &name);
        void setObjDir(OptDirectFlag odf);
        int addRows(int nrs);
        int addCols(int ncs);
        void setRowName(int i, const std::string& name);
        void setColName(int j, const std::string& name);
        void setRowBnds(int i, TypeOfSrtucturalVariable type, double lb, double ub);
        void setColBnds(int j, TypeOfSrtucturalVariable type, double lb, double ub);
        void setObjCoef(int j, double coef);
        void setMatRow(int i, int len, const int ind[], const double val[]);
        void setMatRow(int i, std::vector<double> val);
        void setMatCol(int j, int len, const int ind[], const double val[]);
        void setMatCol(int j, std::vector<double> val);
        void setLoadMatrix(int ne, const int rows[], const int colums[], const double val[]);
        void setLoadMatrix(std::vector<std::vector<double>> mat);
        void setLoadMatrix(std::vector<std::tuple<int,int,double>> mat);
        int checkDup(int m, int n, int ne, const int ia[], const int ja[]);
        int checkDup(int m, int n, std::vector<std::tuple<int,int,double>> &mat);
        void sortMatrix();
        void delRows(int nrs, const int num[]);
        void delCols(int ncs, const int num[]);
        void copyProb( LPS& lps, Permition names);
        void eraseProb();
        std::string getProbName();
        std::string getObjName();
        OptDirectFlag getObjDir();
        int getNumRows();
        int getNumCols();
        std::string getRowName(int i);
        std::string getColName(int j);
        TypeOfSrtucturalVariable getRowType(int i);
        double getRowLb(int i);
        double getRowUb(int i);
        TypeOfSrtucturalVariable getColType(int j);
        double getColLb(int j);
        double getColUb(int j);
        double getObjCoef(int j);
        int getNumNz();
        int getMatRow(int i, int ind[], double val[]);
        int getMatRow(int i, std::tuple<int,double> &row);
        void getMatRows(std::vector<std::tuple<int,double>> &rows);
        int getMatCol(int j, int ind[], double val[]);
        int getMatCol(int j, std::tuple<int,double> &col);
        void getMatCols(std::vector<std::tuple<int,double>> &cols);
        void createIndex();
        int findRow(std::string name);
        int findCol(std::string name);
        void deleteIndex();

        double getRowPrim(const int i);
        void getRowPrim(std::vector<double>& rows, const size_t n = 0);
        double getRowDual(const int i);
        void getRowDual(std::vector<double>& rows, const size_t n = 0);
        StatusOfStrucuralVariable getColStat(const int j);
        void getColStat(std::vector<StatusOfStrucuralVariable>& cols, const size_t n = 0);
        double getColPrim(const int j);
        void getColPrim(std::vector<double>& cols, const size_t n = 0);
        double getColDual(const int j);
        void getColDual(std::vector<double>& cols, const size_t n = 0);

        SMResult simplex();
        SMResult exact();

        void printSol(std::string filename);
        int writeProb(int flags, std::string filename);
        
        wSmcp& getSmcp();
        
    private:
        glp_prob* prob;
        wSmcp* smcp;
        
    };
    enum class LPS::OptDirectFlag : int{
        MIN = 1, // minimization
            MAX = 2, // maximization
    };

    enum class LPS::TypeOfSrtucturalVariable : int{
        FR = 1,     // free (unbounded) variable
            LO = 2, // variable with lower bound
            UP = 3, // variable with upper bound
            DB = 4, // double-bounded variable
            FX = 5, // fixed variable
    };

    enum class LPS::KindOfStructuralVariable : int{
        CV = 1, // continuous variable
            IV = 2, // integer variable
            BV = 3, // binary variable
    };
    
    enum class LPS::StatusOfStrucuralVariable : int{
        BS = 1, // basic variable
            NL = 2, // non-basic variable on lower bound
            NU = 3, // non-basic variable on upper bound
            NF = 4, // non-basic free (unbounded) variable
            NS = 5, // non-basic fixed variable
    };

    enum class ScalingOption : int{
        SF_GM = 0x01, // perform geometric mean scaling
            SF_EQ = 0x10, // perform equilibration scaling
            SF_2N = 0x20, // round scale ffactors to power of two
            SF_SKIP = 0x40, // skip if problem is well scaled
            SF_AUTO = 0x80, // choose scaling options automatically
    };

    enum class SolutionIndicator : int{
        SOL = 1, // basic soution
            IPT = 2, // interior-point solution
            MIP = 3, // mixed integer solution
    };

    enum class SolutionStatus : int{
        UNDEF = 1, // solution is undefined
            FEAS = 2, // solution is feasible
            INFEAS = 3, // solution is feasible
            NOFEAS = 4, // no feasible solution exists
            OPT = 5, // solution is optimal
            UNBND = 6, // solution is unbounded
    };

    enum class  Permition : bool{
        ON = 1, // enable something
            OFF = 0, // disable something
    };

    enum class SMMsgLevel : char{
        MSG_OFF = 0, // no output
            MSG_ERR = 1, // warning and error messages only
            MSG_ON = 2, // normal output
            MSG_ALL = 3, // full output
            MSG_DBG = 4, // debug output
    };
    
    enum class SMOption : char{
        PRIMAL = 1, // use primal simplex
            DUALP = 2, // use dual; if it fails, use primal
            DUAL = 3, // use dual simplex
    };

    enum class SMPrincingTec : char{
        PT_STD = 0x11, // standard (Dantzig rule)
            PT_PSE = 0x22, // projected steepest edge
    };
    
    enum class SMRatioTestTec : char{
        RT_STD = 0x11, // standard (textbook)
            RT_HAR = 0x22, // two-pass Harris' ratio test
    };

    enum class SMResult : int{
        EBADB = 0x01, // invalid basis
            ESING = 0x02, // singular matrix
            ECOND = 0x03, // ill-conditioned matrix
            EBOUND = 0x04, // invalid bounds
            EFAIL = 0x05, // solver failed
            EOBJLL = 0x06, // objective lower limit reached
            EOBJUL = 0x07, // objective upper limit reached
            EITLIM = 0x08, // iteration limit exceede
            ETMLIM = 0x09, // time limit exceeded
            ENOPFS = 0x0A, // no primal feasible solution
            ENODFS = 0x0B, // no dual feasible solution
            EROOT = 0x0C, // root LP optimum not provided
            ESTOP = 0x0D, // search terminatedd by application
            EMIPGAP = 0x0E, // relative mip gap tolerance reached
            ENOFEAS = 0x0F, // no primal/dual feasible solution
            ENOCVG = 0x10, // no convergence
            EINSTAB = 0x11, // numerical instability
            EDATA = 0x12, // invalid data
            EORANGE = 0x13, // result out of range
            };
}

#endif

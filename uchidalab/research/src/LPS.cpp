#include "LPS.hpp"
#include "glpk.h"
#include "wSmcp.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <cmath>

using namespace std;

namespace {
    const double EPS = 1.0e-14;
}

namespace lps{
    // LPS.hppの方に直打ちしたのでコメントアウト
    /*
    enum class LPS::OptDirectFlag : int{
        MIN = GLP_MIN,
            MAX = GLP_MAX,
    };

    enum class LPS::TypeOfSrtucturalVariable : int{
        FR = GLP_FR,
            LO = GLP_LO,
            UP = GLP_UP,
            DB = GLP_DB,
            FX = GLP_FX,
    };

    enum class LPS::KindOfStructuralVariable : int{
        CV = GLP_CV,
            IV = GLP_IV,
            BV = GLP_BV,
    };

    
    enum class LPS::StatusOfStrucuralVariable : int{
        BS = GLP_BS,
            NL = GLP_NL,
            NU = GLP_NU,
            NF = GLP_NF,
            NS = GLP_NS,
    };

    enum class ScalingOption : int{
        SF_GM = GLP_SF_GM,
            SF_EQ = GLP_SF_EQ,
            SF_2N = GLP_SF_2N,
            SF_SKIP = GLP_SF_SKIP,
            SF_AUTO = GLP_SF_AUTO,
    };

    enum class SolutionIndicator : int{
        SOL = GLP_SOL,
            IPT = GLP_IPT,
            MIP = GLP_MIP,
    };

    enum class SolutionStatus : int{
        UNDEF = GLP_UNDEF,
            FEAS = GLP_FEAS,
            INFEAS = GLP_INFEAS,
            NOFEAS = GLP_NOFEAS,
            OPT = GLP_OPT,
            UNBND = GLP_UNBND,
    };

    enum class  Permition : bool{
        ON = GLP_ON,
            OFF = GLP_OFF,
    };

    enum class SMMsgLevel : char{
        MSG_OFF = GLP_MSG_OFF,
            MSG_ERR = GLP_MSG_ERR,
            MSG_ON = GLP_MSG_ON,
            MSG_ALL = GLP_MSG_ALL,
            MSG_DBG = GLP_MSG_DBG,
    };
    
    enum class SMOption : char{
        PRIMAL = GLP_PRIMAL,
            DUALP = GLP_DUALP,
            DUAL = GLP_DUAL,
    };

    enum class SMPrincingTec : char{
        PT_STD = GLP_PT_STD,
            PT_PSE = GLP_PT_PSE,
    };
    
    enum class SMRatioTestTec : char{
        RT_STD = GLP_RT_STD,
            RT_HAR = GLP_RT_HAR,
    };

    enum class SMResult : int{
        EBADB = GLP_EBADB,
            ESING = GLP_ESING,
            ECOND = GLP_ECOND,
            EBOUND = GLP_EBOUND,
            EFAIL = GLP_EFAIL,
            EOBJLL = GLP_EOBJLL,
            EOBJUL = GLP_EOBJUL,
            EITLIM = GLP_EITLIM,
            ETMLIM = GLP_ETMLIM,
            ENOPFS = GLP_ENOPFS,
            ENODFS = GLP_ENODFS,
            EROOT = GLP_EROOT,
            ESTOP = GLP_ESTOP,
            EMIPGAP = GLP_EMIPGAP,
            ENOFEAS = GLP_ENOFEAS,
            ENOCVG = GLP_ENOCVG,
            EINSTAB = GLP_EINSTAB,
            EDATA = GLP_EDATA,
            EORANGE = GLP_ERANGE
            };
    
*/
    
    LPS::LPS() : prob(nullptr), smcp(nullptr){
        prob = glp_create_prob();
        smcp = new wSmcp();
        glp_init_smcp(&smcp->gsmcp);
    }

    LPS::~LPS(){
        glp_delete_prob(prob);
        delete smcp;
    }

    void LPS::setProbName(const std::string &name){
        glp_set_prob_name(this->prob, name.c_str());
    }

    void LPS::setObjName(const std::string &name){
        glp_set_obj_name(this->prob, name.c_str());
    }

    void LPS::setObjDir(lps::LPS::OptDirectFlag odf){
        glp_set_obj_dir(this->prob, static_cast<int>(odf));
    }

    int LPS::addRows(int nrs){
        if(nrs <= 0) return 0;
        return glp_add_rows(this->prob, nrs);
    }

    int LPS::addCols(int ncs){
        if(ncs <= 0) return 0;
        return glp_add_cols(this->prob, ncs);
    }

    void LPS::setRowName(int i, const std::string &name){
        glp_set_row_name(this->prob, i, name.c_str());
    }

    void LPS::setColName(int j, const std::string &name){
        glp_set_col_name(this->prob, j, name.c_str());
    }

    void LPS::setRowBnds(int i, TypeOfSrtucturalVariable type, double lb, double ub){
        glp_set_row_bnds(this->prob, i, static_cast<int>(type), lb, ub);
    }

    void LPS::setColBnds(int j, TypeOfSrtucturalVariable type, double lb, double ub){
        glp_set_col_bnds(this->prob, j, static_cast<int>(type), lb, ub);
    }

    void LPS::setObjCoef(int j, double coef){
        glp_set_obj_coef(this->prob, j, coef);
    }

    void LPS::setMatRow(int i, std::vector<double> rows){
        int len=0;
        auto ind = std::vector<int>(1);
        auto val = std::vector<double>(1);
        for(int i=0; i<rows.size(); ++i){
            if(std::abs(rows[i]) <= EPS){
                ind.push_back(i+1);
                val.push_back(rows[i]);
            }
        }
        glp_set_mat_row(this->prob, i, static_cast<int>(ind.size()), &ind[0], &val[0]);
    }

    void LPS::setMatRow(int i, int len, const int *ind, const double *val){
        glp_set_mat_row(this->prob, i, len, ind, val);
    }

    void LPS::setMatCol(int j, std::vector<double> cols){
        int len = 0;
        auto ind = std::vector<int>(1);
        auto val = std::vector<double>(1);
        
        for(int i=0; i<cols.size(); ++i){
            if(std::abs(cols[i]) <= EPS){
                ind.push_back(i+1);
                val.push_back(cols[i]);
            }
        }
        glp_set_mat_col(this->prob, j, static_cast<int>(ind.size()), &ind[0], &val[0]);
    }

    void LPS::setMatCol(int j, int len, const int *ind, const double *val){
        glp_set_mat_col(this->prob, j, len, ind, val);
    }

    void LPS::setLoadMatrix(int ne, const int *rows, const int *colums,
                            const double *val)
    {
        glp_load_matrix(this->prob, ne, rows, colums, val);
    }
    
    void LPS::setLoadMatrix(std::vector<std::vector<double> > mat){
        auto ia = std::vector<int>(1);
        auto ja = std::vector<int>(1);
        auto val = std::vector<double>(1);
        
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[i].size(); ++j){
                if(std::abs(mat[j][i]) <= EPS){
                    ia.push_back(i+1);
                    ja.push_back(j+1);
                    val.push_back(mat[j][i]);
                }
            }
        }
        glp_load_matrix(this->prob, static_cast<int>(val.size()), &ia[0], &ja[0], &val[0]);
    }

    // 0スタート
    void LPS::setLoadMatrix(std::vector<std::tuple<int, int, double> > mat){
        auto ia = std::vector<int>(1);
        auto ja = std::vector<int>(1);
        auto val = std::vector<double>(1);

        for(auto& tu : mat){
            ia.push_back(get<0>(tu));
            ja.push_back(get<1>(tu));
            val.push_back(get<2>(tu));
        }
        
        glp_load_matrix(this->prob, mat.size(), &ia[0], &ja[0], &val[0]);
    }

    int LPS::checkDup(int m, int n, int ne, const int *ia, const int *ja){
        return glp_check_dup(m, n, ne, ia, ja);
    }

    int LPS::checkDup(int m, int n, std::vector<std::tuple<int,int,double>>& mat){
        vector<int> ia(1);
        vector<int> ja(1);

        for(auto& tu : mat){
            ia.push_back(get<0>(tu));
            ja.push_back(get<1>(tu));
        }

        int tmp = glp_check_dup(m, n, mat.size(), &ia[0], &ja[0]);
        return (tmp < 0 ? tmp+1 : (tmp > 0 ? tmp-1 : 0));

    }

    void LPS::sortMatrix(){
        glp_sort_matrix(this->prob);
    }

    void LPS::delRows(int nrs, const int *num){
        glp_del_rows(this->prob, nrs, num);
    }

    void LPS::delCols(int ncs, const int *num){
        glp_del_cols(this->prob, ncs, num);
    }

    void LPS::copyProb(lps::LPS &lps, lps::LPS::Permition names){
        glp_copy_prob(lps.prob, this->prob, static_cast<int>(names));
    }

    void LPS::eraseProb(){
        glp_erase_prob(this->prob);
    }

    std::string LPS::getProbName(){
        return std::string( glp_get_prob_name(this->prob) );
    }

    std::string LPS::getObjName(){
        return std::string( glp_get_obj_name(this->prob) );
    }

    LPS::OptDirectFlag LPS::getObjDir(){
        return OptDirectFlag( glp_get_obj_dir(this->prob) );
    }

    int LPS::getNumRows(){
        return glp_get_num_rows(this->prob);
    }

    int LPS::getNumCols(){
        return glp_get_num_cols(this->prob);
    }

    string LPS::getRowName(int i){
        return std::string( glp_get_row_name(this->prob, i) );
    }

    string LPS::getColName(int j){
        return std::string( glp_get_col_name(this->prob, j) );
    }

    LPS::TypeOfSrtucturalVariable LPS::getRowType(int i){
        return TypeOfSrtucturalVariable( glp_get_row_type(this->prob, i) );
    }

    double LPS::getRowLb(int i){
        return glp_get_row_lb(this->prob, i);
    }

    double LPS::getRowUb(int i){
        return glp_get_row_ub(this->prob, i);
    }

    LPS::TypeOfSrtucturalVariable LPS::getColType(int j){
        return TypeOfSrtucturalVariable( glp_get_col_type(this->prob, j) );
    }

    double LPS::getColLb(int i){
        return glp_get_col_lb(this->prob, i);
    }

    double LPS::getColUb(int j){
        return glp_get_col_ub(this->prob, j);
    }

    double LPS::getObjCoef(int j){
        return glp_get_obj_coef(this->prob, j);
    }

    int LPS::getNumNz(){
        return glp_get_num_nz(this->prob);
    }

    int LPS::getMatRow(int i, int *ind, double *val){
        return glp_get_mat_row(this->prob, i, ind, val);
    }

    int LPS::getMatRow(int i, std::tuple<int, double> &row){
        return 0;
    }

    void LPS::getMatRows(std::vector<std::tuple<int, double> > &rows){
        
    }

    int LPS::getMatCol(int j, int *ind, double *val){
        return glp_get_mat_col(this->prob, j, ind, val);
    }

    int LPS::getMatCol(int j, std::tuple<int, double> &col){
        return 0;
    }

    void LPS::getMatCols(std::vector<std::tuple<int, double> > &cols){
        
    }

    void LPS::createIndex(){
        glp_create_index(this->prob);
    }

    int LPS::findRow(std::string name){
        return glp_find_row(this->prob, name.c_str());
    }

    int LPS::findCol(std::string name){
        return glp_find_col(this->prob, name.c_str());
    }

    void LPS::deleteIndex(){
        glp_delete_index(this->prob);
    }

    double LPS::getRowPrim(const int i){
        return glp_get_row_prim(this->prob, i);
    }

    void LPS::getRowPrim(std::vector<double>& rows, const size_t n ){
        if( n != 0 ){
            rows.resize(n);
        }
        
        for(int i=0; i<rows.size(); ++i){
            rows[i] = getRowPrim(i+1);
        }
    }

    double LPS::getRowDual(const int i){
        return glp_get_row_dual(this->prob, i);
    }

    void LPS::getRowDual(std::vector<double> &rows, const size_t n ){
        if( n != 0 ){
            rows.resize(n);
        }
        
        for(int i=0; i<rows.size(); ++i){
            rows[i] = getRowDual(i+1);
        }        
    }

    LPS::StatusOfStrucuralVariable LPS::getColStat(const int j){
        return StatusOfStrucuralVariable( glp_get_col_stat(this->prob, j) );
    }

    void LPS::getColStat(std::vector<StatusOfStrucuralVariable> &cols, const size_t n){
        if( n != 0 ){
            cols.resize(n);
        }
        
        for(int i=0; i<cols.size(); ++i){
            cols[i] = getColStat(i+1);
        }
    }

    double LPS::getColPrim(int j){
        return glp_get_col_prim(this->prob, j);
    }

    void LPS::getColPrim(std::vector<double> &cols, const size_t n ){
        if( n != 0 ){
            cols.resize(n);
        }
        
        for(int i=0; i<cols.size(); ++i){
            cols[i] = getColPrim(i+1);
        }
    }

    double LPS::getColDual(int j){
        return glp_get_col_dual(this->prob, j);
    }

    void LPS::getColDual(std::vector<double> &cols, const size_t n){
        if( n != 0 ){
            cols.resize(n);
        }
        
        for(int i=0; i<cols.size(); ++i){
            cols[i] = getColDual(i+1);
        }
    }

    LPS::SMResult LPS::simplex(){
        return SMResult(glp_simplex(this->prob, &this->smcp->gsmcp));
    }

    LPS::SMResult LPS::exact(){
        return SMResult(glp_exact(this->prob, &this->smcp->gsmcp));
    }

    void LPS::printSol(std::string filename){
        glp_print_sol(this->prob, filename.c_str());
    }

    int LPS::writeProb(int flags, std::string filename){
        return glp_write_prob(this->prob, flags, filename.c_str());
    }

    wSmcp& LPS::getSmcp(){
        return *this->smcp;
    }
    
}

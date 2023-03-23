#ifndef MYANA_h
#define MYANA_h

#include "mppcjp.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include <queue>



using namespace std;

class MyAna : public mppcjp {
public:
    MyAna(TTree *tree=0):mppcjp(tree){};
    ~MyAna() {};
    virtual void Loop(string infname, string outfname);
    void initialize(string infname, string outfname);
    void execute();
    void finalize();
    void clear();

private:
    int mac_num;
    TFile *m_file;
    // *************** Variables to be used is registered here ********************


    int pene_event_count;
    int total_event;
    int total_trigger;

    int det1_start;
    int det2_start;
    int det3_start;
    int det4_start;

    int last_chg[32];
    int last_ts;
    int last_sec_cnt;
    bool last_ABhit;

    int up_cnt;
    int down_cnt;

    int up_cnt_timecut;
    int down_cnt_timecut;





    TH1D *pene_event_ADC_hist;
    TH2D *vis_of_4layers;


   
    // ****************************************************************************
};
#endif

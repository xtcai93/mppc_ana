#include "MyAna.h"
#include <iostream>
#include <cmath>
#include <TROOT.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <string.h>
#include <stdio.h>
#include "TSystem.h"

#include "TGraph.h"

#include <vector>
#include <algorithm>



void MyAna::Loop (string infname, string outfname)
{
    //  cout << "Loop()" << endl;

    initialize (infname, outfname);

    if (fChain == 0)
        return;

    Long64_t nentries = fChain->GetEntriesFast ();
    Int_t nbytes = 0, nb = 0;

    for (Long64_t jentry = 0; jentry < nentries; jentry++)
    {
        Long64_t ientry = LoadTree (jentry);
        if (ientry < 0)
            break;
        nb = fChain->GetEntry (jentry);
        nbytes += nb;

        clear ();
        execute ();

    }

    finalize ();

}

void MyAna::initialize (string infname, string outfname)
{

    cout << "initialize()" << endl;
    // ********************** Create ROOT variables for analysis *************************
   char *out = (char *) outfname.c_str ();
    m_file = new TFile (out, "recreate");


    //*********************** Initialize *************************************
    pene_event_count = 0;
    total_event = 0;
    total_trigger = 0;

    last_ts = 0;
    last_sec_cnt = 0;
    last_ABhit = 0;
    up_cnt = 0;
    down_cnt = 0;
    up_cnt_timecut = 0;
    down_cnt_timecut = 0;
    pene_event_ADC_hist = new TH1D ("pene_ADC", "penetrating ADC value hist", 1000, 0, 4090);


    //***************input channel number for each det*****************
    // cout<<"please input the starting channel for det 1: (starting from 0)"<<endl;
    // cin>>det1_start;
    // cout<<"please input the starting channel for det 2: "<<endl;
    // cin>>det2_start;
    // cout<<"please input the starting channel for det 3: "<<endl;
    // cin>>det3_start;
    // cout<<"please input the starting channel for det 4: "<<endl;
    // cin>>det4_start;
    // cout<<"input completed..."<<endl;
 
    
}


bool isScinHit (int threshold, int ch1, int ch2, int ch3, int ch4, int ch5, int ch6)
{
    if (ch1 > threshold || ch2 > threshold || ch3 > threshold || ch4 > threshold || ch5 > threshold || ch6 > threshold) 
    return 1;

    else return 0; 
}

int max_ADC_value (int ch1, int ch2, int ch3, int ch4, int ch5, int ch6)
{
    int max = 0;
    if (ch1 > max) max = ch1;
    if (ch2 > max) max = ch2;
    if (ch3 > max) max = ch3;
    if (ch4 > max) max = ch4;
    if (ch5 > max) max = ch5;
    if (ch6 > max) max = ch6;
    return max;
}




void MyAna::execute ()
{
    total_trigger++;

    bool isAhit = 0;
    bool isBhit = 0;
    bool isChit = 0;
    bool isDhit = 0;

    int t_delta = 0;

    int max_A = max_ADC_value(ADC_ch00, ADC_ch01, ADC_ch02, ADC_ch03, ADC_ch04, ADC_ch05);
    int max_B = max_ADC_value(ADC_ch06, ADC_ch07, ADC_ch08, ADC_ch09, ADC_ch10, ADC_ch11);
    int max_C = max_ADC_value(ADC_ch18, ADC_ch19, ADC_ch20, ADC_ch21, ADC_ch22, ADC_ch23);
    int max_D = max_ADC_value(ADC_ch24, ADC_ch25, ADC_ch26, ADC_ch27, ADC_ch28, ADC_ch29);

    isAhit = isScinHit(400, ADC_ch00, ADC_ch01, ADC_ch02, ADC_ch03, ADC_ch04, ADC_ch05);
    isBhit = isScinHit(400, ADC_ch06, ADC_ch07, ADC_ch08, ADC_ch09, ADC_ch10, ADC_ch11);
    isChit = isScinHit(400, ADC_ch18, ADC_ch19, ADC_ch20, ADC_ch21, ADC_ch22, ADC_ch23);
    isDhit = isScinHit(400, ADC_ch24, ADC_ch25, ADC_ch26, ADC_ch27, ADC_ch28, ADC_ch29);

    // event where at least 1 channel is larger than threshold in all 4 dets 
    if (isAhit && isBhit && isChit && isDhit) 
    {
        pene_event_count++;
        pene_event_ADC_hist->Fill(max_A);
        pene_event_ADC_hist->Fill(max_B);
        pene_event_ADC_hist->Fill(max_C);
        pene_event_ADC_hist->Fill(max_D);
       

    }


    // event where at least one channel is larger than threshold in any det
    if (isAhit || isBhit || isChit || isDhit) 
    {
        total_event++;
    }


    // when previous entry has only A hit and B hit
    if (last_ABhit) 
    {
        if (sec_cnt == last_sec_cnt){
            t_delta = ts - last_ts;
        }
        else t_delta = ts + 1000000000 - last_ts;

        if (isAhit && isBhit && !isChit && !isDhit )
        {
            up_cnt++;
            if (t_delta < 5800) up_cnt_timecut++;
        }

        if (!isAhit && !isBhit && isChit && isDhit)
        {
            down_cnt++;
            if (t_delta < 5800) down_cnt_timecut++;
        }
     
    }

    // set flag back to 0
    last_ABhit = 0;


    // if A and B are hit, C and D not hit, store the info for next entry
    if (isAhit && isBhit && (!isChit) && (!isDhit)) 
    {
        ADC_ch00 = last_chg[0];
        ADC_ch01 = last_chg[1];
        ADC_ch02 = last_chg[2];
        ADC_ch03 = last_chg[3];
        ADC_ch04 = last_chg[4];
        ADC_ch05 = last_chg[5];
        ADC_ch06 = last_chg[6];
        ADC_ch07 = last_chg[7];
        ADC_ch08 = last_chg[8];
        ADC_ch09 = last_chg[9];
        ADC_ch10 = last_chg[10];
        ADC_ch11 = last_chg[11];
        ADC_ch12 = last_chg[12];
        ADC_ch13 = last_chg[13];
        ADC_ch14 = last_chg[14];
        ADC_ch15 = last_chg[15];
        ADC_ch16 = last_chg[16];
        ADC_ch17 = last_chg[17];
        ADC_ch18 = last_chg[18];
        ADC_ch19 = last_chg[19];
        ADC_ch20 = last_chg[20];
        ADC_ch21 = last_chg[21];
        ADC_ch22 = last_chg[22];
        ADC_ch23 = last_chg[23];
        ADC_ch24 = last_chg[24];
        ADC_ch25 = last_chg[25];
        ADC_ch26 = last_chg[26];
        ADC_ch27 = last_chg[27];
        ADC_ch28 = last_chg[28];
        ADC_ch29 = last_chg[29];
        ADC_ch30 = last_chg[30];
        ADC_ch31 = last_chg[31];

        last_ts = ts;
        last_sec_cnt = sec_cnt;

        last_ABhit = 1;

    }




}


void MyAna::finalize ()
{
    cout<<"Finalizing......"<<endl;
    m_file->cd();
    // **************************** Your finalizing here *********************************
    cout<<"test for mppc jp file"<<endl;
    cout<<"total trigger is "<<total_trigger<<endl;
    cout<<"with threshold of 400, total event number with hit is "<<total_event<<endl;
    cout<<"event number where 4 dets are hit is "<<pene_event_count<<endl;
    cout<<"without time and energy cut, preliminary up count is "<<up_cnt<<endl;
    cout<<"preliminary down count is "<<down_cnt<<endl;
    cout<<"with time cut of 5.8 us, up count is "<<up_cnt_timecut<<endl;
    cout<<"down count is "<<down_cnt_timecut<<endl;
    


    // ***********************************************************************************
    m_file->Write ();
    m_file->Close ();
}

void MyAna::clear (){}

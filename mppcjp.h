//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 20 10:49:06 2023 by ROOT version 6.24/02
// from TTree mppcjp/Preprocessing of mppc tree for further analysis
// found on file: mppcjp_phase1_test4.root
//////////////////////////////////////////////////////////

#ifndef mppcjp_h
#define mppcjp_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class mppcjp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UShort_t        ADC_ch00;
   UShort_t        ADC_ch01;
   UShort_t        ADC_ch02;
   UShort_t        ADC_ch03;
   UShort_t        ADC_ch04;
   UShort_t        ADC_ch05;
   UShort_t        ADC_ch06;
   UShort_t        ADC_ch07;
   UShort_t        ADC_ch08;
   UShort_t        ADC_ch09;
   UShort_t        ADC_ch10;
   UShort_t        ADC_ch11;
   UShort_t        ADC_ch12;
   UShort_t        ADC_ch13;
   UShort_t        ADC_ch14;
   UShort_t        ADC_ch15;
   UShort_t        ADC_ch16;
   UShort_t        ADC_ch17;
   UShort_t        ADC_ch18;
   UShort_t        ADC_ch19;
   UShort_t        ADC_ch20;
   UShort_t        ADC_ch21;
   UShort_t        ADC_ch22;
   UShort_t        ADC_ch23;
   UShort_t        ADC_ch24;
   UShort_t        ADC_ch25;
   UShort_t        ADC_ch26;
   UShort_t        ADC_ch27;
   UShort_t        ADC_ch28;
   UShort_t        ADC_ch29;
   UShort_t        ADC_ch30;
   UShort_t        ADC_ch31;
   UInt_t          ts;
   UInt_t          ts_ref;
   UInt_t          ts_delta;
   UInt_t          sec_cnt;

   // List of branches
   TBranch        *b_ADC_ch00;   //!
   TBranch        *b_ADC_ch01;   //!
   TBranch        *b_ADC_ch02;   //!
   TBranch        *b_ADC_ch03;   //!
   TBranch        *b_ADC_ch04;   //!
   TBranch        *b_ADC_ch05;   //!
   TBranch        *b_ADC_ch06;   //!
   TBranch        *b_ADC_ch07;   //!
   TBranch        *b_ADC_ch08;   //!
   TBranch        *b_ADC_ch09;   //!
   TBranch        *b_ADC_ch10;   //!
   TBranch        *b_ADC_ch11;   //!
   TBranch        *b_ADC_ch12;   //!
   TBranch        *b_ADC_ch13;   //!
   TBranch        *b_ADC_ch14;   //!
   TBranch        *b_ADC_ch15;   //!
   TBranch        *b_ADC_ch16;   //!
   TBranch        *b_ADC_ch17;   //!
   TBranch        *b_ADC_ch18;   //!
   TBranch        *b_ADC_ch19;   //!
   TBranch        *b_ADC_ch20;   //!
   TBranch        *b_ADC_ch21;   //!
   TBranch        *b_ADC_ch22;   //!
   TBranch        *b_ADC_ch23;   //!
   TBranch        *b_ADC_ch24;   //!
   TBranch        *b_ADC_ch25;   //!
   TBranch        *b_ADC_ch26;   //!
   TBranch        *b_ADC_ch27;   //!
   TBranch        *b_ADC_ch28;   //!
   TBranch        *b_ADC_ch29;   //!
   TBranch        *b_ADC_ch30;   //!
   TBranch        *b_ADC_ch31;   //!
   TBranch        *b_ts;   //!
   TBranch        *b_ts_ref;   //!
   TBranch        *b_ts_delta;   //!
   TBranch        *b_sec_cnt;   //!

   mppcjp(TTree *tree=0);
   virtual ~mppcjp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef mppcjp_cxx
mppcjp::mppcjp(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("mppcjp_phase1_test4.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("mppcjp_phase1_test4.root");
      }
      f->GetObject("mppcjp",tree);

   }
   Init(tree);
}

mppcjp::~mppcjp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mppcjp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mppcjp::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void mppcjp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ADC_ch00", &ADC_ch00, &b_ADC_ch00);
   fChain->SetBranchAddress("ADC_ch01", &ADC_ch01, &b_ADC_ch01);
   fChain->SetBranchAddress("ADC_ch02", &ADC_ch02, &b_ADC_ch02);
   fChain->SetBranchAddress("ADC_ch03", &ADC_ch03, &b_ADC_ch03);
   fChain->SetBranchAddress("ADC_ch04", &ADC_ch04, &b_ADC_ch04);
   fChain->SetBranchAddress("ADC_ch05", &ADC_ch05, &b_ADC_ch05);
   fChain->SetBranchAddress("ADC_ch06", &ADC_ch06, &b_ADC_ch06);
   fChain->SetBranchAddress("ADC_ch07", &ADC_ch07, &b_ADC_ch07);
   fChain->SetBranchAddress("ADC_ch08", &ADC_ch08, &b_ADC_ch08);
   fChain->SetBranchAddress("ADC_ch09", &ADC_ch09, &b_ADC_ch09);
   fChain->SetBranchAddress("ADC_ch10", &ADC_ch10, &b_ADC_ch10);
   fChain->SetBranchAddress("ADC_ch11", &ADC_ch11, &b_ADC_ch11);
   fChain->SetBranchAddress("ADC_ch12", &ADC_ch12, &b_ADC_ch12);
   fChain->SetBranchAddress("ADC_ch13", &ADC_ch13, &b_ADC_ch13);
   fChain->SetBranchAddress("ADC_ch14", &ADC_ch14, &b_ADC_ch14);
   fChain->SetBranchAddress("ADC_ch15", &ADC_ch15, &b_ADC_ch15);
   fChain->SetBranchAddress("ADC_ch16", &ADC_ch16, &b_ADC_ch16);
   fChain->SetBranchAddress("ADC_ch17", &ADC_ch17, &b_ADC_ch17);
   fChain->SetBranchAddress("ADC_ch18", &ADC_ch18, &b_ADC_ch18);
   fChain->SetBranchAddress("ADC_ch19", &ADC_ch19, &b_ADC_ch19);
   fChain->SetBranchAddress("ADC_ch20", &ADC_ch20, &b_ADC_ch20);
   fChain->SetBranchAddress("ADC_ch21", &ADC_ch21, &b_ADC_ch21);
   fChain->SetBranchAddress("ADC_ch22", &ADC_ch22, &b_ADC_ch22);
   fChain->SetBranchAddress("ADC_ch23", &ADC_ch23, &b_ADC_ch23);
   fChain->SetBranchAddress("ADC_ch24", &ADC_ch24, &b_ADC_ch24);
   fChain->SetBranchAddress("ADC_ch25", &ADC_ch25, &b_ADC_ch25);
   fChain->SetBranchAddress("ADC_ch26", &ADC_ch26, &b_ADC_ch26);
   fChain->SetBranchAddress("ADC_ch27", &ADC_ch27, &b_ADC_ch27);
   fChain->SetBranchAddress("ADC_ch28", &ADC_ch28, &b_ADC_ch28);
   fChain->SetBranchAddress("ADC_ch29", &ADC_ch29, &b_ADC_ch29);
   fChain->SetBranchAddress("ADC_ch30", &ADC_ch30, &b_ADC_ch30);
   fChain->SetBranchAddress("ADC_ch31", &ADC_ch31, &b_ADC_ch31);
   fChain->SetBranchAddress("ts", &ts, &b_ts);
   fChain->SetBranchAddress("ts_ref", &ts_ref, &b_ts_ref);
   fChain->SetBranchAddress("ts_delta", &ts_delta, &b_ts_delta);
   fChain->SetBranchAddress("sec_cnt", &sec_cnt, &b_sec_cnt);
   Notify();
}

Bool_t mppcjp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mppcjp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t mppcjp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef mppcjp_cxx

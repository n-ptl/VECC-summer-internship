#include <iostream>
#include <vector>
#include<TObject.h>

void read_raw_file() {

    // Histograms
    TCanvas* c1;
    c1 = new TCanvas();
  
    TCanvas* c2;
    c2 = new TCanvas();
  
    TCanvas* c3;
    c3 = new TCanvas();
  
    TCanvas* c4;
    c4 = new TCanvas();

    //Station 1 
    TH2I* hS1L1M1 = new TH2I("hS1L1M1", "Station 1 layer 1", 40, 0, 18, 200, 30000, 55000);
    hS1L1M1->SetLineColor(kRed);
    hS1L1M1->GetXaxis()->SetTitle("Module No.");
    hS1L1M1->GetYaxis()->SetTitle("Digi Counts");
    
    TH2I* hS1L2M1 = new TH2I("hS1L2M1", "Station 1 layer 2", 40, 0, 18, 200, 30000, 55000);
    hS1L2M1->SetLineColor(kBlue);
    
    TH2I* hS1L3M1 = new TH2I("hS1L3M1", "Station 1 layer 3", 40, 0, 18, 200, 30000, 55000);
    hS1L3M1->SetLineColor(kBlack);
    
    TH2D* hModuleChargeS1 = new TH2D("hModuleChargeS1", "Charge per Module S1", 20, 0, 20, 3, 0, 3);
    TH1D* hTotalChargeS1= new TH1D("hTotalChargeS1", "Total ADC per Event S1", 500, 0, 50000);
    TH2D* hADCvsTimeS1 = new TH2D("hADCvsTimeS1", "ADC vs Time", 500, 0, 2e5, 20 ,0, 20);
    hADCvsTimeS1->GetXaxis()->SetTitle("Time");
    hADCvsTimeS1->GetYaxis()->SetTitle("Module");
    
    //Station 2
    TH2I* hS2L1M1 = new TH2I("hS2L1M1", "Station 2 layer 1", 42, 0, 21, 200, 5000, 13000);
    hS2L1M1->SetLineColor(kRed);
    hS2L1M1->GetXaxis()->SetTitle("Module No.");
    hS2L1M1->GetYaxis()->SetTitle("Digi Counts");
    
    TH2I* hS2L2M1 = new TH2I("hS2L2M1", "Station 2 layer 2", 42, 0, 21, 200, 5000, 13000);    
    hS2L2M1->SetLineColor(kBlue);
    
    TH2I* hS2L3M1 = new TH2I("hS2L3M1", "Station 2 layer 3", 42, 0, 21, 200, 5000, 13000);
    hS2L3M1->SetLineColor(kBlack);
    
    TH2D* hModuleChargeS2 = new TH2D("hModuleChargeS2", "Charge per Module S2", 20, 0, 20, 3, 0, 3);
    TH1D* hTotalChargeS2 = new TH1D("hTotalChargeS2", "Total ADC per Event S2", 500, 0, 50000);
    TH2D* hADCvsTimeS2 = new TH2D("hADCvsTimeS2", "ADC vs Time", 500, 0, 2e5, 20 ,0, 20);
    hADCvsTimeS2->GetXaxis()->SetTitle("Time");
    hADCvsTimeS2->GetYaxis()->SetTitle("Module");
    
    //Station 3
    TH2I* hS3L1M1 = new TH2I("hS3L1M1", "Station 3 layer 1", 42, 0, 21, 200, 1400, 3700);  
    hS3L1M1->SetLineColor(kRed);
    hS3L1M1->GetXaxis()->SetTitle("Module No.");
    hS3L1M1->GetYaxis()->SetTitle("Digi Counts");
    
    
    TH2I* hS3L2M1 = new TH2I("hS3L2M1", "Station 3 layer 2", 42, 0, 21, 200, 1400, 3700);
    hS3L2M1->SetLineColor(kBlue);
    
    TH2I* hS3L3M1 = new TH2I("hS3L3M1", "Station 3 layer 3", 42, 0, 21, 200, 1400, 3700);
    hS3L3M1->SetLineColor(kBlack);
    
    TH2D* hModuleChargeS3 = new TH2D("hModuleChargeS3", "Charge per Module S3", 20, 0, 20, 3, 0, 3);
    TH1D* hTotalChargeS3 = new TH1D("hTotalChargeS3", "Total ADC per Event S3", 500, 0, 50000); 
    TH2D* hADCvsTimeS3 = new TH2D("hADCvsTimeS3", "ADC vs Time", 500, 0, 2e5, 20 ,0, 20);
    hADCvsTimeS3->GetXaxis()->SetTitle("Time");
    hADCvsTimeS3->GetYaxis()->SetTitle("Module");
    
    //Station 4
    TH2I* hS4L1M1 = new TH2I("hS4L1M1", "Station 4 layer 1", 42, 0, 21, 200, 300, 1300);
    hS4L1M1->SetLineColor(kRed);
    hS4L1M1->GetXaxis()->SetTitle("Module No.");
    hS4L1M1->GetYaxis()->SetTitle("Digi Counts");
    
    TH2I* hS4L2M1 = new TH2I("hS4L2M1", "Station 4 layer 2", 42, 0, 21, 200, 300, 1300);
    hS4L2M1->SetLineColor(kBlue);
    
    TH2I* hS4L3M1 = new TH2I("hS4L3M1", "Station 4 layer 3", 42, 0, 21, 200, 300, 1300);
    hS4L3M1->SetLineColor(kBlack);
    
    TH2D* hModuleChargeS4 = new TH2D("hModuleChargeS4", "Charge per Module S4", 20, 0, 20, 3, 0, 3);
    TH1D* hTotalChargeS4 = new TH1D("hTotalChargeS4", "Total ADC per Event S4", 500, 0, 50000);
    TH2D* hADCvsTimeS4 = new TH2D("hADCvsTimeS4", "ADC vs Time", 500, 0, 2e5, 20, 0, 20);
    hADCvsTimeS4->GetXaxis()->SetTitle("Time");
    hADCvsTimeS4->GetYaxis()->SetTitle("Module");
    
    //Define Counter
    int fNdigisS1[3][16] = {0};
    int fNdigisS2[3][20] = {0};
    int fNdigisS3[3][18] = {0};
    int fNdigisS4[3][18] = {0};

    // Open File
    TFile* input_file = TFile::Open("testn.raw.root");

    if (!input_file || input_file->IsZombie()) {
        std::cout << "Cannot open file\n";
        return;
    }
    std::vector<CbmMuchDigi> *digi_vector = 0;
    TBranch *digi = 0;
  
    // Get Tree
    TTree* tree = (TTree*) input_file->Get("cbmsim");

    if (!tree) {
        std::cout << "Tree not found\n";
        return;
    }
    
    //Set Branch Address 
    tree->SetBranchAddress("MuchDigi", &digi_vector, &digi);

    //Event Loop
    Int_t nEvents1 = tree->GetEntries();
      for (Int_t iEvent1 = 0; iEvent1 < nEvents1; iEvent1++){
      
      Int_t iE = tree->LoadTree(iEvent1);
      digi->GetEntry(iE); 
      Int_t N_digi = digi_vector->end() - digi_vector->begin();
      
      //Station 1 Counter Reset
      for (int l = 0; l < 3; l++){
        for (int m = 0; m < 16; m++) {
        fNdigisS1[l][m] = 0;
        }
      }
      double totalChargeEvent1 = 0;
      
      //Station 2 Counter Reset
      for (int l = 0; l < 3; l++){
        for (int m = 0; m < 20; m++) {
        fNdigisS2[l][m] = 0;
        }
      }
      double totalChargeEvent2 = 0;
      
      //Station 3 Counter Reset
      for (int l = 0; l < 3; l++){
        for (int m = 0; m < 18; m++) {
        fNdigisS3[l][m] = 0;
        }
      }
      double totalChargeEvent3 = 0;
      
      //Station 4 Counter Reset
      for (int l = 0; l < 3; l++){
        for (int m = 0; m < 18; m++) {
        fNdigisS4[l][m] = 0;
        }
      }
      double totalChargeEvent4 = 0;
      
      
      //cout<<nEvents1<<endl;
   
      //Loop over Digis 
      for(std::vector<CbmMuchDigi>::iterator iDigi1 = digi_vector->begin(); iDigi1 != digi_vector->end(); iDigi1++) 
      { 
            
        Int_t stId = CbmMuchAddress::GetStationIndex(iDigi1->GetDetectorId());
	Int_t layerId = CbmMuchAddress::GetLayerIndex(iDigi1->GetDetectorId());
	Int_t layerSideId = CbmMuchAddress::GetLayerSideIndex(iDigi1->GetDetectorId()); 
        Int_t moduleId = CbmMuchAddress::GetModuleIndex(iDigi1->GetDetectorId()); 
	Int_t sectorId = CbmMuchAddress::GetSectorIndex(iDigi1->GetDetectorId());
	
	
           //Count digis for Station 1 
           if (stId == 0){
           int layer  = layerId;                 // 0,1,2
           int moduleid = 2 * moduleId + layerSideId;
           double charge = iDigi1->GetCharge();
           
           totalChargeEvent1 += charge;
           hADCvsTimeS1->Fill(iDigi1->GetTime(), moduleid, charge);
           hModuleChargeS1->Fill(moduleid, layer, charge);

           if (layer >= 0 && layer < 3 &&
           moduleid >= 0 && moduleid < 16){

            fNdigisS1[layer][moduleid]++;
            }
          }
          
          //Count digis for Station 2 
           if (stId == 1){
           int layer  = layerId;                 // 0,1,2
           int moduleid = 2 * moduleId + layerSideId;
           double charge = iDigi1->GetCharge();
           
           totalChargeEvent2 += charge;
           hADCvsTimeS2->Fill(iDigi1->GetTime(), moduleid, charge);
           hModuleChargeS2->Fill(moduleid, layer, charge);

           if (layer >= 0 && layer < 3 &&
           moduleid >= 0 && moduleid < 20){

            fNdigisS2[layer][moduleid]++;
            }
          }
          
          //Count digis for Station 3 
           if (stId == 2){
           int layer  = layerId;                 // 0,1,2
           int moduleid = 2 * moduleId + layerSideId;
           double charge = iDigi1->GetCharge();
           
           totalChargeEvent3 += charge;
           hADCvsTimeS3->Fill(iDigi1->GetTime(), moduleid, charge);
           hModuleChargeS3->Fill(moduleid, layer, charge);

           if (layer >= 0 && layer < 3 &&
           moduleid >= 0 && moduleid < 18){

            fNdigisS3[layer][moduleid]++;
            }
          }
          
          //Count digis for Station 4 
           if (stId == 3){
           int layer  = layerId;                 // 0,1,2
           int moduleid = 2 * moduleId + layerSideId;
           double charge = iDigi1->GetCharge();
           
           totalChargeEvent4 += charge;
           hADCvsTimeS4->Fill(iDigi1->GetTime(), moduleid, charge);
           hModuleChargeS4->Fill(moduleid, layer, charge);

           if (layer >= 0 && layer < 3 &&
           moduleid >= 0 && moduleid < 18){

            fNdigisS4[layer][moduleid]++;
           
            }            
          }                       
        }
        
        /*cout<<fNdigisS3[0][18]<<endl;
        cout<<fNdigisS4[0][18]<<endl;
        cout<<fNdigisS3[0][19]<<endl;
        cout<<fNdigisS4[0][19]<<endl;*/
        
        //Fill Histogram for Station 1               
        for (int m = 0; m < 16; m++) {
          hS1L1M1->Fill(m + 1, fNdigisS1[0][m]);
          hS1L2M1->Fill(m + 1, fNdigisS1[1][m]);
          hS1L3M1->Fill(m + 1, fNdigisS1[2][m]);
        }
        
        //Fill Histogram for Station 2               
        for (int m = 0; m < 20; m++) {
          hS2L1M1->Fill(m + 1, fNdigisS2[0][m]);
          hS2L2M1->Fill(m + 1, fNdigisS2[1][m]);
          hS2L3M1->Fill(m + 1, fNdigisS2[2][m]);
        }
        
        //Fill Histogram for Station 3               
        for (int m = 0; m < 18; m++) {
          hS3L1M1->Fill(m + 1, fNdigisS3[0][m]);
          hS3L2M1->Fill(m + 1, fNdigisS3[1][m]);
          hS3L3M1->Fill(m + 1, fNdigisS3[2][m]);
        }
        
        //Fill Histogram for Station 4               
        for (int m = 0; m < 18; m++) {
          hS4L1M1->Fill(m + 1, fNdigisS4[0][m]);
          hS4L2M1->Fill(m + 1, fNdigisS4[1][m]);
          hS4L3M1->Fill(m + 1, fNdigisS4[2][m]);
        }
        //Fill Histogram
          hTotalChargeS1->Fill(totalChargeEvent1); 
          hTotalChargeS2->Fill(totalChargeEvent2); 
          hTotalChargeS3->Fill(totalChargeEvent3); 
          hTotalChargeS4->Fill(totalChargeEvent4);      
     }             
        
   TFile* fout = new TFile("histogram.root", "RECREATE");

    //Plot Hist for Station 1 on Canvas
    c1->cd(); 
    hS1L1M1->Write();
    hS1L1M1->Draw("Box");
    
    hS1L2M1->Write();
    hS1L2M1->Draw("BOX SAME");
    
    hS1L3M1->Write();
    hS1L3M1->Draw("Box SAME");
    c1->BuildLegend();
//    c1->SetOptHist(0);

    //Plot Hist for Station 2 on Canvas
    c2->cd(); 
    hS2L1M1->Write();
    hS2L1M1->Draw("Box");
    
    hS2L2M1->Write();
    hS2L2M1->Draw("BOX SAME");
    
    hS2L3M1->Write();
    hS2L3M1->Draw("Box SAME");
    c2->BuildLegend();
    
    //Plot Hist for Station 3 on Canvas
    c3->cd(); 
    hS3L1M1->Write();
    hS3L1M1->Draw("Box");
    
    hS3L2M1->Write();
    hS3L2M1->Draw("BOX SAME");
    
    hS3L3M1->Write();
    hS3L3M1->Draw("Box SAME");
    c3->BuildLegend();
    
    //Plot Hist for Station 4 on Canvas
    c4->cd(); 
    hS4L1M1->Write();
    hS4L1M1->Draw("Box");
    
    hS4L2M1->Write();
    hS4L2M1->Draw("BOX SAME");
    
    hS4L3M1->Write();
    hS4L3M1->Draw("Box SAME");
    c4->BuildLegend();
    
    //ADC vs Time
    hADCvsTimeS1->Write();
    //hADCvsTimeS1->Draw("CLOZ");
    hADCvsTimeS2->Write();
    hADCvsTimeS3->Write();
    hADCvsTimeS4->Write();
    
    //Module charge
    hModuleChargeS1->Write();
    hModuleChargeS2->Write();
    hModuleChargeS3->Write();
    hModuleChargeS4->Write();
    
    //Total Charge
    hTotalChargeS1->Write();
    hTotalChargeS2->Write(); 
    hTotalChargeS3->Write();
    hTotalChargeS4->Write();

    fout->Close();

    std::cout << "\nHistograms saved to histogram.root\n";  
   
}

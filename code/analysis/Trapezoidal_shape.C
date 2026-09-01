#include <TCanvas.h>
#include <TPolyLine.h>
#include <TMath.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TBox.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <TLatex.h>

using namespace std;

bool readMappingFromFile(const char* filename,
                         vector<int>& mappingxx,
                         vector<int>& mappingyy)
{
    ifstream file(filename);

    if(!file.is_open())
    {
        cout<<"Cannot open "<<filename<<endl;
        return false;
    }

    string line;
    bool readX=false;
    bool readY=false;

    while(getline(file,line))
    {
        if(line.find("mappingxx")!=string::npos)
        {
            readX=true;
            continue;
        }

        if(line.find("mappingyy")!=string::npos)
        {
            readX=false;
            readY=true;
            continue;
        }

        if(readX)
        {
            stringstream ss(line);
            string token;

            while(getline(ss,token,','))
            {
                token.erase(remove(token.begin(),token.end(),'{'),token.end());
                token.erase(remove(token.begin(),token.end(),'}'),token.end());

                if(token.size()>0)
                {
                    try
                    {
                        mappingxx.push_back(stoi(token));
                    }
                    catch(...) {}
                }
            }
        }

        if(readY)
        {
            stringstream ss(line);
            string token;

            while(getline(ss,token,','))
            {
                token.erase(remove(token.begin(),token.end(),'{'),token.end());
                token.erase(remove(token.begin(),token.end(),'}'),token.end());

                if(token.size()>0)
                {
                    try
                    {
                        mappingyy.push_back(stoi(token));
                    }
                    catch(...) {}
                }
            }
        }
    }

    file.close();

    cout<<"mappingxx size = "<<mappingxx.size()<<endl;
    cout<<"mappingyy size = "<<mappingyy.size()<<endl;

    return true;
}

void Trapezoidal_shape()
{
    gStyle->SetOptStat(0);

    vector<int> mappingxx;
    vector<int> mappingyy;

    if(!readMappingFromFile("mapping.txt",mappingxx,mappingyy))
        return;

Color_t FebColor[18] =
{   
    kRed ,      
    kAzure-9,
    kSpring-8,
    kOrange-3,
    kViolet-7,
    kCyan-6,
    kYellow-8,
    kMagenta-8,
    kTeal-6,

    kPink-8,
    kAzure+5,
    kSpring+3,
    kOrange+2,
    kViolet+2,
    kCyan+2,
    kGreen+1,

    kRed-8,     
    kGray+2
};

    const int NROWS = 97;
    const int NCOLS = 23;

    const double Rin  = 15.7;
    const double Rout = 80.3 + Rin;

    const double TotalAngle = 10.0*TMath::DegToRad();

    vector<double> Radius(NROWS+1);

    double Weight[NROWS];
    double SumWeight = 0.0;

    for(int i=0;i<NROWS;i++)
    {
        Weight[i] = 1.0 + 0.025*i;
        SumWeight += Weight[i];
    }

    Radius[0] = Rin;

    for(int i=0;i<NROWS;i++)
    {
        double dr = (Rout-Rin)*Weight[i]/SumWeight;
        Radius[i+1] = Radius[i] + dr;
    }

    TCanvas *c1 =
    new TCanvas("c1", "18 FEB Detector Map",   1800,    1400);

    c1->Range(-25.0,    0.0,     25.0,  100.0);

    for(int ch=0; ch<(int)mappingxx.size(); ch++)
    {
        int col = mappingxx[ch];
        int row = mappingyy[ch]-1;

        if(col < 0) continue;
        if(row < 0) continue;
        if(row >= NROWS) continue;

        int feb = ch/128;

        if(feb < 0 || feb > 17)
            continue;

        double r1 = Radius[row];
        double r2 = Radius[row+1];

        double phi1 =
        -TotalAngle/2.0
        +
        col*(TotalAngle/NCOLS);

        double phi2 =
        -TotalAngle/2.0
        +
        (col+1)*(TotalAngle/NCOLS);

        double x[5];
        double y[5];

        x[0] = r1*sin(phi1);
        y[0] = r1*cos(phi1);

        x[1] = r1*sin(phi2);
        y[1] = r1*cos(phi2);

        x[2] = r2*sin(phi2);
        y[2] = r2*cos(phi2);

        x[3] = r2*sin(phi1);
        y[3] = r2*cos(phi1);

        x[4] = x[0];
        y[4] = y[0];

        TPolyLine *pad =
        new TPolyLine(5,x,y);

        pad->SetFillColor(FebColor[feb]);
        pad->SetFillStyle(1001);
        pad->SetLineColor(kBlack);
        pad->SetLineWidth(1);

        pad->Draw("f");
        pad->Draw();
    }
    
    TLatex latex;
    latex.SetTextAlign(22);
    latex.SetTextSize(0.015);
    latex.SetTextFont(42);

for(int row=0; row<97; row+=3)
{
    double rmid = 0.5*(Radius[row] + Radius[row+1]);

    double phiLeft = -TotalAngle/2.0 - 0.005 ;

    double xrow = rmid*sin(phiLeft);
    double yrow = rmid*cos(phiLeft);

    latex.DrawLatex(xrow,yrow,Form("%d",row));
}

double rTop = Radius[97] + 2.0;

for(int col=0; col<23; col++)
{
    double phi = -TotalAngle/2.0 + (col+1.5)*(TotalAngle/23.0);

    double xcol = rTop*sin(phi);
    double ycol = rTop*cos(phi);

    latex.DrawLatex(xcol,ycol,Form("%d",col+1));
}

    TLegend *leg =
    new TLegend(0.82,
                0.08,
                0.98,
                0.92);

    for(int i=0;i<18;i++)
    {
        TBox *b = new TBox();
        b->SetFillColor(FebColor[i]);

        leg->AddEntry(
            b,
            Form("FEB %d",i),
            "f");
    }

    leg->SetBorderSize(1);
    leg->Draw();

    c1->SaveAs("GEM_Mapping_18FEB.png");
    c1->Update();

    cout<<"Inner Radius = "<<Rin<<" cm"<<endl;
    cout<<"Outer Radius = "<<Rout<<" cm"<<endl;
    cout<<"Opening Angle = 22 deg"<<endl;
}

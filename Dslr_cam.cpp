#include "Dslr_cam.h"
#include<iostream>      //for input output
#include<conio.h>       //for clrscr() and getch()
#include<dos.h>        // for delay
#include<graphics.h>   // for graphics
#include<stdlib.h>     //all the standard libraries in c++
#include<fstream>     //to read and write the files
#include<stdio.h>     //to use pass strings in arrays
#include<ctime>       //to use computer time
#include<windows.h>  //to use images

using namespace std;


Dslr_cam::Dslr_cam(){
	setZoom(25.00);
	setAperture(5.00);
	setShutrspd(200);
	setIso(1250);
}

Dslr_cam::Dslr_cam(double zoom, double aperture, double shutrspd, int ayeso){
	setZoom(zoom);
	setAperture(aperture);
	setShutrspd(shutrspd);
	setIso(ayeso);
}

Dslr_cam::~Dslr_cam(){
	//destructor
}


//all my accessors in one place
void Dslr_cam::setZoom(const double zo){
	Zoom = zo;
}

double Dslr_cam::getZoom() const{
	return Zoom;
}

void Dslr_cam::setAperture(const double ap){
	Aperture = ap;
}

double Dslr_cam::getAperture() const{
	return Aperture;
}

void Dslr_cam::setShutrspd(const double shtr){
	ShutterSpeed = shtr;
}

double Dslr_cam::getShutrspd() const {
	return ShutterSpeed;
}

void Dslr_cam::setIso(const int iso){
	ISO900 = iso;
}

int Dslr_cam::getIso() const {
	return ISO900;
}
//calculate exposure

//intro block begins

void Dslr_cam:: give_intro()
{
	cout<<endl;
	cout<<"The Following is a basic simulator for a DSLR camera, the program simulates"<<endl;
	cout<<"four basic functionalities i.e Zooming, Aperture Setting, Shutter Speed & IS0"<<endl;
	cout<<"C++ project by Suraj Gaud                                                  "<<endl;
    cout<<endl<<endl<<endl;
	cout<<"Select 1 for Documentation"<<endl<<endl<<"Select 2 to Continue with the program"<<endl;
	string output;
	int helpinput;
	cin>>helpinput;

	if(helpinput == 1) {

		ifstream helpfile;
		helpfile.open("CPProject_Documentation.txt");
		while(!helpfile.eof()) {
			getline(helpfile,output);
			cout<<output<<endl;
		}

		helpfile.close();
		return setting_selection();
	} else if (helpinput == 2) {
		return setting_selection();
	} else {
		cout<<"INVALID CHOICE!!";
		return setting_selection();
	}
}


//intro block ends

//settings block starts



void Dslr_cam::setting_selection(){



	//char exp[25] = {"Exposure"};

	cout<<endl;
	cout<<"This is DSLR is loaded with default settings!!"<<endl;
	cout<<"Respond with 1 for Default or 2  for Manual mode"<<endl;
	int resp;
    double zm,apr,shttr;
    int eyeso;
	cin>>resp;
	initwindow(600,400);
	draw_box();
		if(resp == 1) {

		Dslr_cam defalt;
		cout<<"The default loaded values are:"<<endl;
		cout<<"Current Zoom  "<<defalt.getZoom()<<" mm"<<endl;
		cout<<"Current Aperture  "<<defalt.getAperture()<<" f-stop"<<endl;
		cout<<"New ISO set to: "<<defalt.getIso()<<" Level"<<endl;
		cout<<"Current Shutter Speed  "<<defalt.getShutrspd()<<" per sec"<<endl;
        initwindow(600,400);
        readimagefile("default.jpg",0,0,600,400);
        draw_box();
        return snap();



	} else if(resp == 2){

		cout<<endl<<"Using Standard 18-55 mm lens"<<endl<<endl;
		cout<<"Set Zoom (18-200) ";
		cin>>zm;
		cout<<endl;
		cout<<"Set Aperture (2.00-11.5) ";
		cin>>apr;
		cout<<endl;
		cout<<"Set ISO Level (1250-3200) ";
		cin>>eyeso;
		cout<<endl;
		cout<<"Set Shutter Speed (200-1000)";
		cin>>shttr;
		cout<<endl;
        float exp = zm*apr/eyeso;
        cout<<"Legend: "<<endl;
        cout<<"Values in between -0.25 and 0.25 are balanced"<<endl;
        cout<<"Values less than -0.25 are under exposed"<<endl;
        cout<<"Values greater than 0.25 are over exposed"<<endl;
        cout<<"The current exposure value is "<<exp<<endl<<endl;

        Dslr_cam settings(zm,apr,eyeso,shttr);
        cout<<endl;
        cout<<"New Zoom Set to: "<<settings.getZoom()<<" mm"<<endl;
        cout<<"New aperture set to: "<<settings.getAperture()<<" f-stop"<<endl;
        cout<<"New ISO set to: "<<settings.getIso()<<" Level"<<endl;
        cout<<"New Shutter Speed set to: "<<settings.getShutrspd()<<" per sec"<<endl;

			if (zm >= 40 && zm <= 55){
				cout <<endl<<"Zooming in"<<endl;

                closegraph();
                initwindow(600,400);
                readimagefile("zoom200.jpg",0,0,600,400);
                draw_box();
                char expval[20];
	            sprintf(expval, "%d", exp);
	            outtextxy(300,375,expval);
	            //cleardevice();
			} else if (zm >= 18 && zm <= 24 ){
			    cout <<endl<<"Zooming out"<<endl;
                cleardevice();
                closegraph();
                initwindow(600,400);
				readimagefile("zoomout.jpg",0,0,600,400);
				draw_box();
                char expval[20];
	            sprintf(expval, "%d", exp);
				outtextxy(300,375,expval);

			}if(zm > 55.10) {
			cout<<"This lens can only Zoom to 55 mm "<<endl;
			cout<<"Do you want to interchange with 55-250 mm lens??"<<endl;
			cout<<"Respond with --1-- to change or --2-- to exit"<<endl;
            int lensresp;
			cin>> lensresp;
			initwindow(600,400);
			draw_box();
            char expval[20];
            sprintf(expval, "%d", exp);
            outtextxy(300,375,expval);
			if(lensresp == 1) {
				cout<<endl;
				cout<<"Now using 55-250 mm telescopic lens"<<endl;
				Dslr_cam settings(zm,apr,shttr,eyeso);
				cout<<endl;
				cout<<"New Zoom Set to: "<<settings.getZoom()<<" mm"<<endl;
				cout<<"New aperture set to: "<<settings.getAperture()<<" f-stop"<<endl;
				cout<<"New ISO set to: "<<settings.getIso()<<" f-stop"<<endl;
				cout<<"New Shutter Speed set to: "<<settings.getShutrspd()<<" per sec"<<endl;
                closegraph();
                initwindow(600,400);
                readimagefile("zoom300.jpg",0,0,600,400);
                draw_box();
                char expval[20];
                sprintf(expval, "%d", exp);
                outtextxy(300,375,expval);
                return snap();
			} else if (lensresp == 2 ) {
				exit(0);
}

              return snap();
		      closegraph();

}

}

}
//setting block ends


//snap block begins

void Dslr_cam::snap()
{
	cout<<endl;
	cout<<"Do you want to save this image with these settings??"<<endl<<endl;
	cout<<"Press 1 to save to disk"<<endl<<"Press 2 to Modify Values"<<endl;
	cout<<"Press 3  for shutter test"<<endl;
	int snapin;
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);
	cin>> snapin;
	if(snapin == 1) {
		cout<<"Picture has been saved, see file for details"<<endl;
		cout<<endl;
        ofstream picturelog ("captured.txt");
        if (picturelog.is_open()){
        picturelog << "This Image was captured at.\n"<<dt<<endl;
        picturelog.close();
        return setting_selection();
}

	   else if (snapin == 2) {
       return setting_selection();
}

	    else if(snapin == 3){

	  	cleardevice();
	  	return shutter_test();
}
}
        return setting_selection();
}
//snap block ends


//viewfinder block

void Dslr_cam:: draw_box()
{
                char viewf[50] =  {"Viewfinder"};
                char m1[10] =  {"-1"};char m2[10] =  {"-.75"};
                char m3[10] =  {"-.50"};char m4[10] =  {"-.25"};
                char m5[10] =  {"0.0"};char m6[10] =  {".25"};
                char m7[10] =  {".50"};char m8[10] =  {".75"};
                char m9[10] =  {"+1"};
                settextstyle(10,0,2);
                setcolor(6);
                outtextxy(20,5,viewf);
                rectangle(150,150,450,300);
                line(100,100,150,100);  //1
	            line(100,100,100,150);  //1
	            line(100,300,100,350);  //2
	            line(100,350,150,350);  //2
                line(450,350,500,350);  //3
                line(500,350,500,300);  //3
	            line(500,100,450,100);  //4
                line(500,100,500,150);  //4
                line(200,350,400,350);   //exposure meter
                line(200,340,200,360);
                settextstyle(2,0,4);
                outtextxy(195,330, m1);
                line(225,340,225,360);
                outtextxy(220,330, m2);
                line(250,340,250,360);
                outtextxy(245,330, m3);
                line(275,340,275,360);
                outtextxy(270,330, m4);
                line(300,340,300,360);
                outtextxy(295,330, m5);
                line(325,340,325,360);
                outtextxy(320,330, m6);
                line(350,340,350,360);
                outtextxy(345,330, m7);
                line(375,340,375,360);
                outtextxy(370,330, m8);
                line(400,340,400,360);
                outtextxy(395,330, m9);
}


//vf block ends

//shutter test block begins

void Dslr_cam::shutter_test(){



     int x,y,i;        // Coordinates of the mouse click
     bool red_clicked = false;
     int charge = 100;
     red_clicked = false;
     i = 1;
     while (!ismouseclick(WM_LBUTTONDOWN)){

     	if(!red_clicked){

        char tstarea[50] = {"Left click the area in RED to test!!"};
        setfillstyle(SOLID_FILL, LIGHTRED);
        bar(150,150,450,300);
        rectangle(265,180,325,257);
        settextstyle(10,0,2);
		outtextxy(20, 25, tstarea);
        draw_box();
    	circle(20+i,220,40);
        delay(5);
        i++;
        cleardevice();
    }
	}
	getmouseclick(WM_LBUTTONDOWN, x, y);
	settextstyle(10,0,2);
    char pa[20] = {"Perfecto amigo"};
    char snapl[100] = {"You Snapped too late, try again..!!"};
    char snape[100] = {"You Snapped too early, try again..!!"};

	if (x >= 265 && x<= 325){
		cout<<"Perfect Shot";
		cleardevice();
        readimagefile("perfect.jpg",0,0,600,400);
        draw_box();
        settextstyle(10,0,2);
		outtextxy(20,25, pa);
		return snap();

	}else if (x>=326 && x<= 400){
		cout<<"You Snapped too late, try again"<<endl;
        cleardevice();
        readimagefile("late.jpg",0,0,600,400);
        draw_box();
        settextstyle(10,0,2);
		outtextxy(20,25, snapl);
		return snap();

	}else if(x>=100 && x<= 264){
		cout<<" You Snapped too early, try again"<<endl;
        cleardevice();
        readimagefile("early.jpg",0,0,600,400);
        draw_box();
        settextstyle(10,0,2);
		outtextxy(20,25,snape);
		return snap();

	}
	return setting_selection();
}
//shuttertest block ends





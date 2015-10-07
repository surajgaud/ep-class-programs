#ifndef DSLR_CAM_H
#define DSLR_CAM_H

class Dslr_cam
{
	public:

	Dslr_cam(double zoom, double aperture, double shutrspd, int ayeso);


    void setZoom(const double zo);
	void setAperture(const double ap);
	void setShutrspd(const double shtr);
	void setIso(const int iso);

	void give_intro();
    void draw_box();
    void setting_selection();
    void snap();

    void shutter_test();
    double getZoom() const;
    double getAperture() const;
    double getShutrspd() const;
    int getIso() const;

	Dslr_cam();
    virtual ~Dslr_cam();


	private:

		double Zoom;
		double Aperture;
		double ShutterSpeed;
		int Charge;
		int ISO900;
};

#endif

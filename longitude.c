#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846

double deg2rad(double);
double rad2deg(double);

double distance(double lat1, double lon1, double lat2, double lon2) 
{
  double theta, dist;
  if ((lat1 == lat2) && (lon1 == lon2))
   {
    return 0;
  }
  else 
  {
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist*60*1.1515*1.609344;
    return (dist);
  }
}

double deg2rad(double deg) {
  return (deg * pi / 180);
}

double rad2deg(double rad) {
  return (rad * 180 / pi);
}

int main()
{
	double lat1,lat2,lon1,lon2;
	printf("Enter the latitude of the first point: \n");
	scanf("%lf",&lat1);
	printf("Enter the longitude of the first point: \n");
	scanf("%lf",&lon1);
	printf("Enter the latitude of the second point: \n");
	scanf("%lf",&lat2);
	printf("Enter the longitude of the second point: \n");
	scanf("%lf",&lon2);
	double diff=distance(lat1,lon1,lat2,lon2);
	printf("Difference: %lf KM \n",diff);
}

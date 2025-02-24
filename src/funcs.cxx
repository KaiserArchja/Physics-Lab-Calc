#include "../include/funcs.hpp"


std::map<std::string, double> LeastSquare(std::vector<double> x, std::vector<double> y){
    std::map<std::string, double> reg;

    double X_mean = 0;
    double Y_mean = 0;
    for(const double X: x)
        X_mean += X;
    for(const double Y: y)
        Y_mean += Y;

    X_mean /= (double)x.size();
    Y_mean /= (double)y.size();

    double dot = 0;
    double distance = 0;
    for(int i = 0; i < x.size() && i < y.size(); i++){
        dot += (x[i]-X_mean)*y[i];
        distance += pow((x[i]-X_mean), 2);
    }
    
    reg.insert({"Slope", (dot/distance)});

    reg.insert({"Y-Intercept", (Y_mean - reg["Slope"]*X_mean)});

    double SlopeErr = 0;
    double InterceptErr = 0;
    double DistanceErr = 0;

    for(int i = 0; i < x.size() && i < y.size(); i++)
        DistanceErr += pow((y[i] - reg["Slope"]*x[i] - reg["Y-Intercept"]), 2);
    if(x.size() > 2){


    SlopeErr = sqrt((DistanceErr)/(distance*(x.size()-2)));
    

    InterceptErr = sqrt((((1.0/(double)x.size())+(pow(X_mean, 2)/distance))*(DistanceErr/(x.size()-2))));


    }

    reg.insert({"Slope Error", SlopeErr});

    reg.insert({"Y-Intercept Error", InterceptErr});

    double XY = 0;
    double X2 = 0;
    for(int i = 0; i < x.size() && i < x.size(); i++){
        XY += x[i]*y[i];
        X2 += pow(x[i], 2);
    }

    reg.insert({"0Slope", (XY/X2)});

    double SlopeErr0 = 0;
    
    if(x.size() > 1){
        SlopeErr0 = sqrt(((1.0/X2)*(DistanceErr/(x.size()-1))));
    }
    reg.insert({"0Slope Error", SlopeErr0});
    
    return reg;
}

void LeastSquare(){
    int N;
    std::vector<double> x, y;
    std::cout << std::endl << "Number of points:" << std::endl;
    std::cin >> N;
    std::cout << std::endl << "X of points (seperated by space):" << std::endl;
    for(int i = 0; i < N; i++){
        double *hlp = new double;
        std::cin >> *hlp;
        x.push_back(*hlp);
        delete hlp;
    }
    std::cout << std::endl << "Y of points (seperated by space):" << std::endl;
    for(int i = 0; i < N; i++){
        double *hlp = new double;
        std::cin >> *hlp;
        y.push_back(*hlp);
        delete hlp;
    }
    std::map<std::string, double> reg = LeastSquare(x, y);
    std::cout << std::endl << "Slope: " << reg["Slope"] << "\t" << "Y-Intercept: " << reg["Y-Intercept"] << std::endl;
    std::cout << std::endl << "Slope Error: " << reg["Slope Error"] << "\t" << "Y-Intercept Error: " << reg["Y-Intercept Error"] << std::endl;
    std::cout << std::endl << "0Slope: " << reg["0Slope"] << "\t" << "0Slope Error: " << reg["0Slope Error"] << std::endl;

}
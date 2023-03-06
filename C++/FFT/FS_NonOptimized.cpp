#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.14

int main()
{
    std::vector<double> sin_disc;
    sin_disc.reserve(10);
    int T = 1000;
    for (int i = 0; i < T; ++i)
    {
        double n1 = (2*PI*3*i / T);
        double n2 = (2*PI*4*i / T);
        sin_disc.push_back(sin(n1) + cos(n2));
    }
    
    // for (int i = 0; i < sin_disc.size(); ++i)
    // {
    //     std::cout << sin_disc[i] << std::endl;
    // }
    
    int N = sin_disc.size();
    int K = N;

    std::vector<double> real;
    std::vector<double> img;

    real.reserve(10);
    img.reserve(10);

    double real_tmp;
    double img_tmp;

    for (int k = 0; k < K; ++k)
    {
        real_tmp = 0;
        img_tmp = 0;

        for (int n = 0; n < N; ++n)
        {
            real_tmp += sin_disc[n]*cos(2 * PI * k * n /N);
            img_tmp += sin_disc[n]*sin(2 * PI * k * n / N);
        }
        
        real.push_back(real_tmp);
        img.push_back(img_tmp);
    }
    
    std::cout << "k\t real\t\timaginary\n";
    
    for (int k = 0; k < 10; ++k)
    {
        std::cout << k << "\t" << real[k]/T << "\t" << img[k]/T << std::endl;
    }
    

    return 0;
}
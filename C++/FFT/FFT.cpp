#include <iostream>
#include <vector>
#include <complex>
#include <cmath>


std::vector<std::complex<double>> FFT(std::vector<std::complex<double>>& samples)
{
    // Find the number of samples we have
    int N = samples.size();

    // Execute the end ofo the recursive even/odd splits once we only have one sample
    if(N == 1)
        return samples;
    
    // Splitt the samples into even and odd subsums
    // Find half the total number of samples
    int M = N / 2;

    // Declare an even and an odd complex vector
    std::vector<std::complex<double>> Xeven(M, 0);
    std::vector<std::complex<double>> Xodd(M, 0);
    
    // Input the even and odd samples into respective vectors
    for (int i = 0; i < M; ++i)
    {
        Xeven[i] = samples[2*i];
        Xodd[i]  = samples[2*i + 1];
    }

    // Perform the recursive FFT operation on the odd and even sides
    std::vector<std::complex<double>> Feven(M, 0);
    Feven = FFT(Xeven);

    std::vector<std::complex<double>> Fodd(M, 0);
    Fodd = FFT(Xodd);

    //----------END RECURSION----------//
    // Declare vector of frequency bins
    std::vector<std::complex<double>> freqbins(N, 0);

    // Define pi = 3.14159265
    double pi = 3.14159265;

    // Combinethe values found
    for (int k = 0; k < N / 2; ++k)
    {
        //For each split set, we need to multiply a k-dependent complex
        // numberr by the odd subsum
        std::complex<double> cmplxExponential = std::polar(1.0, -2*pi*k / N ) * Fodd[k];
        freqbins[k] = Feven[k] + cmplxExponential;

        // Everytime you add pi, exponential changes sign
        freqbins[k + N/2] = Feven[k] - cmplxExponential;
    }

    return freqbins;
     
    
}

std::vector<std::complex<double>> SignalDiscretization(int N)
{
    // Evaluatin number of points in period; # of period = std::pow(2, n), because we need divide N by power of 2 to get integer size of sample array 
    
    std::vector<std::complex<double>> samples(N, 0);

    double pi = 3.14159265;

    for (int i = 0; i < N; ++i)
    {
        samples[i].real(4*std::sin(2*pi*5*i / N));
        samples[i].imag(0);
    }
    

    return samples;
}

int main()
{
    int N = std::pow(2, 11);
    // int N = 32000;

    auto samples = SignalDiscretization(N);

    auto freqBin = FFT(samples);

    std::cout << freqBin.size();
    std::cout << "\n\n";

    for (int i = 0; i < N/2; ++i)
    {
        // Normilize freq. bins
        auto freqBinI = freqBin[i].operator/=(N/2);
        if(std::abs(freqBin[i]) > 1)
            std::cout << "freq" << i << " = " << freqBin[i] << "\t\t, abs = " << std::abs(freqBinI) << std::endl;
    }
    
    // Calculating the real "analog" frequency
    // We have discrete frequency: 
    

}
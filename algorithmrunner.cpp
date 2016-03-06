#include "algorithmrunner.h"

#include <QDebug>

AlgorithmRunner::AlgorithmRunner()
    : k_eps(0.1f), k_N(10000)
{    
}

AlgorithmRunner::flipCoins(int m, int n){
    qDebug() << "Received " << m << " and " << n;

    // first coin is biased, flip head with p = 1/2 + eps
    p_hat.append(getProportionOfHeads(n, true));

    // the rest of the coins are not
    for(int i = 0; i < m; ++i){
        p_hat.append(getProportionOfHeads(n));
    }

    // now what?
}

double AlgorithmRunner::getProportionOfHeads(int n, bool biased){
    int sum =0;
    double thresh_prob = .5;
    if (biased) thresh_prob -= k_eps;

    for(int i = n-1; i; i--)
        sum += (qrand() / RAND_MAX > thresh_prob) ? 1 : 0;

    return static_cast<double>(sum) / n;
}

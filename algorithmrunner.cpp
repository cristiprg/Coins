#include "algorithmrunner.h"

#include <QDebug>
#include <QTime>
#include <QtMath>

AlgorithmRunner::AlgorithmRunner()
    : k_eps(0.1), k_N(10000)
{    
    qsrand(QTime::currentTime().msec());
}

inline bool AlgorithmRunner::isCorrectGuess(){
    return *std::max_element(p_hat.begin(), p_hat.end()) == p_hat[0];
}

void AlgorithmRunner::refresh(int m){
    p_hat.clear();
    p_hat.resize(m);
    m_nrIncorrectGuesses = 0;
}

void AlgorithmRunner::flipCoinsNTimes(int m, int n){
    refresh(m);

    // compute number of incorrect guesses
    for (int i = k_N; i; --i){
        flipCoins(m, n);

        // if the first element is NOT the greatest, then it is incorrect guess
        if (!isCorrectGuess()) ++m_nrIncorrectGuesses;
    }

    // compute theoretical bounds
    m_bound = (m-1) * qExp(-n*k_eps*k_eps);

    updateUI();
}

void AlgorithmRunner::updateUI(){
    m_incorrectGuessesTextField->setProperty("text", m_nrIncorrectGuesses);
    m_computedBoundTextField->setProperty("text", m_bound);

}

void AlgorithmRunner::flipCoins(int m, int n){

    // first coin is biased, flip head with p = 1/2 + eps
    p_hat[0] = getProportionOfHeads(n, true);

    // the rest of the coins are not
    for(int i = 1; i < m; ++i){
        p_hat[i] = getProportionOfHeads(n);
    }    
}

void AlgorithmRunner::setIncorrectGuessesTextField(QObject *value)
{
    m_incorrectGuessesTextField = value;
}

void AlgorithmRunner::setComputedBoundTextField(QObject *value)
{
    m_computedBoundTextField = value;
}

double AlgorithmRunner::getProportionOfHeads(int n, bool biased){
    int sum =0;
    double thresh_prob = .5;
    if (biased) thresh_prob -= k_eps;

    for(int i = n; i; i--){

        // here's the flip happening
        sum += (static_cast<double>(qrand()) / RAND_MAX >= thresh_prob) ? 1 : 0;
    }

    return static_cast<double>(sum) / n;
}


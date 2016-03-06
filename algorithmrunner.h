#ifndef ALGORITHMRUNNER_H
#define ALGORITHMRUNNER_H

#include <QObject>
#include <QVector>

class AlgorithmRunner : public QObject
{

Q_OBJECT

private:
   const double k_eps;
   const int k_N;

   /**
    * @brief getProportionOfHeads Flips a coin n times and returns the proportion of heads
    * @param n the number of flips
    * @param biased indicates whether to bias the results of the flip in favor of the head with k_eps
    * @return the proprtion of heads
    */
   double getProportionOfHeads(int n, bool biased = false);

   QVector<double> p_hat;
public slots:
/**
 * @brief flipCoins Flips the coins m_n times and computes for each one the proportion of heads and stores it in p_hat.
 */
    flipCoins(int, int);


public:
    AlgorithmRunner();
    QVector<double> getP_hat(){
        return p_hat;
    }

};

#endif // ALGORITHMRUNNER_H

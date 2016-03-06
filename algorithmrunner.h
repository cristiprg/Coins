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

   QVector<double> p_hat;
   int m_nrIncorrectGuesses;
   double m_bound;

   QObject* m_incorrectGuessesTextField;
   QObject* m_computedBoundTextField;

   /**
    * @brief getProportionOfHeads Flips a coin n times and returns the proportion of heads
    * @param n the number of flips
    * @param biased indicates whether to bias the results of the flip in favor of the head with k_eps
    * @return the proprtion of heads
    */
   double getProportionOfHeads(int n, bool biased = false);

   /**
    * @brief flipCoins Flips the coins m_n times and computes for each one the proportion of heads and stores it in p_hat.
    * @param m the number of coins
    * @param n the number of flips
    */
   void flipCoins(int m, int n);

   /**
    * @brief isCorrectGuess checks whether the assumption that p_hat[0] is the greatest is true or not
    * @return true if p_hat[0] is greatest, false otherwise
    */
   bool isCorrectGuess();

   /**
    * @brief refresh Clears all the variables from previous runs of the algorithm
    * @param m the number of elements (coins) to allocate memory for
    */
   void refresh(int m);

public slots:
   /**
     * @brief flipCoinsNTimes The main function of this application. It calls the flipCoins(m, n) procedure N times and counts the number of
     * incorrect guesses, i.e. where the p_hat[0] is not the greatest. This information is sent to GUI and updates the text field.
    * @param m the number of coins
    * @param n the number of flips
     */
    void flipCoinsNTimes(int, int);


    void updateUI();
public:
    AlgorithmRunner();
    void setIncorrectGuessesTextField(QObject *value);
    void setComputedBoundTextField(QObject *value);
};

#endif // ALGORITHMRUNNER_H

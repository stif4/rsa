#include "generatorsimplenumber.h"
#include <QRandomGenerator>

generatorSimpleNumber::generatorSimpleNumber()
{
}

int generatorSimpleNumber::generateNumber()
{
    int randNuber;

     while (1)
     {
         int z = 0;

         randNuber = QRandomGenerator::global()->bounded(100000);

         for (int i = 2; i < randNuber; i++)
         {
            if (randNuber % i == 0 && randNuber!=0)
            {
                z = 1;
                break;
            }

          }
          if(z == 0)
          {
              break;
          }
      }

    return randNuber;
}


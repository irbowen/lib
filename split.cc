
#include "helper.h"
#include "simple_clock.h"
#include <string>
#include <vector>
#include <iostream>

int main() {

  std::string str1 = "Money is a tool of exchange, which can't exist unless there are goods produced and men able to produce them.";
  std::string str2 = "This is a very long quote that will allow me to test my sting splitting lib.  Hopefully, we can test the performance of all three of these splitters.";
  std::string str3 = "When you accept money in payment for your effort, you do so only on the conviction that you will exchange it for the product of the effort of others. It is not the moochers or the looters who give value to money. Not an ocean of tears not all the guns in the world can transform those pieces of paper in your wallet into the bread you will need to survive tomorrow. Those pieces of paper, which should have been gold, are a token of honor–your claim upon the energy of the men who produce. Your wallet is your statement of hope that somewhere in the world around you there are men who will not default on that moral principle which is the root of money, Is this what you consider evil?\n  Have you ever looked for the root of production? Take a look at an electric generator and dare tell yourself that it was created by the muscular effort of unthinking brutes. Try to grow a seed of wheat without the knowledge left to you by men who had to discover it for the first time. Try to obtain your food by means of nothing but physical motions–and you’ll learn that man’s mind is the root of all the goods produced and of all the wealth that has ever existed on earth.\n  But you say that money is made by the strong at the expense of the weak? What strength do you mean? It is not the strength of guns or muscles. Wealth is the product of man’s capacity to think. Then is money made by the man who invents a motor at the expense of those who did not invent it? Is money made by the intelligent at the expense of the fools? By the able at the expense of the incompetent? By the ambitious at the expense of the lazy? Money is made–before it can be looted or mooched–made by the effort of every honest man, each to the extent of his ability. An honest man is one who knows that he can’t consume more than he has produced.\n  To trade by means of money is the code of the men of good will. Money rests on the axiom that every man is the owner of his mind and his effort. Money allows no power to prescribe the value of your effort except the voluntary choice of the man who is willing to trade you his effort in return. Money permits you to obtain for your goods and your labor that which they are worth to the men who buy them, but no more. Money permits no deals except those to mutual benefit by the unforced judgment of the traders. Money demands of you the recognition that men must work for their own benefit, not for their own injury, for their gain, not their loss–the recognition that they are not beasts of burden, born to carry the weight of your misery–that you must offer them values, not wounds–that the common bond among men is not the exchange of suffering, but the exchange of goods. Money demands that you sell, not your weakness to men’s stupidity, but your talent to their reason; it demands that you buy, not the shoddiest they offer, but the best that your money can find. And when men live by trade–with reaso, not force, as their final arbiter–it is the best product that wins, the best performance, the man of best judgment and highest ability–and the degree of a man’s productiveness is the degree of his reward. This is the code of existence whose tool and symbol is money. Is this what you consider evil?\n  But money is only a tool. It will take you wherever you wish, but it will not replace you as the driver. It will give you the means for the satisfaction of your desires, but it will not provide you with desires. Money is the scourge of the men who attempt to reverse the law of causality–the men who seek to replace the mind by seizing the products of the mind.";



  int test_num = 100000;

  simple_clock::start_clock();
  for (int i = 0; i < test_num; i++) {
    split1(str1, ' ');
    split1(str2, ' ');
    split1(str3, ' ');
  }
  simple_clock::end_clock("Split 1 took");

  simple_clock::start_clock();
  for (int i = 0; i < test_num; i++) {
    split1(str1, ' ');
  }
  simple_clock::end_clock("Split 2 took");
  
  simple_clock::start_clock();
  for (int i = 0; i < test_num; i++) {
    split1(str2, ' ');
  }
  simple_clock::end_clock("Split 3 took");

}

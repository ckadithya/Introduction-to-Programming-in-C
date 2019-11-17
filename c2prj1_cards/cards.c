#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(((c.value>=2)&&(c.value<=VALUE_ACE))&&((c.suit>=SPADES)&&(c.suit<=CLUBS)));
  return;
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT FLUSH";
    break;
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:
    return "FULL_HOUSE";
    break;
  case FLUSH:
    return "FLUSH";
    break;
  case STRAIGHT:
    return "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
    break;
  case TWO_PAIR:
    return "TWO-PAIR";
    break;
  case PAIR:
    return "PAIR";
    break;
  case NOTHING:
    return "NOTHING";
    break;
  default:
    return "???";
  }
  return 0;
    
}

char value_letter(card_t c) {
  if ((c.value>=2)&&(c.value<=9))
    return ('0'+ c.value);
  else
    {
      switch (c.value){
   case VALUE_JACK: return 'J';
   break;
   case VALUE_QUEEN: return 'Q';
   break;
   case VALUE_KING: return 'K';
   break;
   case VALUE_ACE: return 'A';
   break;
   case 10: return '0';
   break;
      default: return '?';
      }
    }
}


char suit_letter(card_t c) {
  switch (c.suit){
 case SPADES: return 's';
  break;
 case HEARTS:return 'h';
   break;
 case DIAMONDS:return 'd';
   break;
 case CLUBS: return 'c';
   break;
 default: return '?';
  }
   
}

void print_card(card_t c) {
  printf("%c,%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (value_let){
  case '2': temp.value=2;break;
  case '3': temp.value=3;break;
  case '4': temp.value=4;break;
  case '5': temp.value=5;break;
  case '6': temp.value=6;break;
  case '7': temp.value=7;break;
  case '8': temp.value=8;break;
  case '9': temp.value=9;break;
  case '0': temp.value=10;break;
  case 'J': temp.value=VALUE_JACK;break;  
  case 'Q': temp.value=VALUE_QUEEN;break;
  case 'K': temp.value=VALUE_KING;break;
  case 'A': temp.value=VALUE_ACE;break;
  }
  switch (suit_let){
  case 's':temp.suit=SPADES;break;
  case 'h':temp.suit=HEARTS;break;
  case 'd':temp.suit=DIAMONDS;break;
  case 'c':temp.suit=CLUBS;break;
  }
  assert(((temp.value>=2)&&(temp.value<=VALUE_ACE))&&((temp.suit>=SPADES)&&(temp.suit<=CLUBS)));
  return temp;
  exit(EXIT_FAILURE);
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if (c>=0 && c<=12)
    temp.suit= SPADES;
  else if(c>=13 && c<=25)
    temp.suit= HEARTS;
  else if(c>=26 && c<=38)
    temp.suit= DIAMONDS;
  else if(c>=39 && c<=51)
    temp.suit= CLUBS;
  temp.value= c%13;
  temp.value= temp.value+2;
    return temp;
}

#ifndef RULE_HPP 
#define RULE_HPP 
#include "Calculator.hpp" 
#include "functions.hpp" 
 
int banquetRule0(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank);
int banquetRule1(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank);

/** 
  * @brief 
  * 
  * @param rule 
  * @param s 
  * @param bestfull 
  * @return void 
  */ 
 void banquetRule(BanquetRule *const &rule, States &s, int *bestfull) { 
     BanquetStrictRule 
         *strictRule[NUM_CHEFS * 
                     DISH_PER_CHEF]; // 下一阶段的规则，不受意图生效次数的影响 
     BanquetLenientRule *lenientRule[NUM_CHEFS * DISH_PER_CHEF]; 
     for (int i = 0; i < NUM_CHEFS* DISH_PER_CHEF; i++) { 
         strictRule[i] = &rule[i].strictRule; 
         lenientRule[i] = &rule[i].lenientRule; 
     } 
     bestfull[0] = banquetRule0(strictRule, lenientRule, s, 0);            
     bestfull[1] = banquetRule1(strictRule, lenientRule, s, 1); 
     return; 
 } 

 int banquetRule0(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank) { 
     int d = rank * DISH_PER_CHEF * CHEFS_PER_GUEST;
     if (s.recipe[d + 0]->cookAbility.knife > 0 &&  //切
         s.recipe[d + 1]->cookAbility.knife > 0 && 
         s.recipe[d + 2]->cookAbility.knife > 0) { 
         for (int i = d + 3; i < d + 6; i++) { 
             if (s.recipe[i]->cookAbility.stirfry > 0) {   //炒
                 strictRule[i]->baseRule.buff += 50; 
             } 
         } 
     }
     if (s.recipe[d + 0]->cookAbility.steam > 0 &&  //蒸
         s.recipe[d + 1]->cookAbility.steam > 0 && 
         s.recipe[d + 2]->cookAbility.steam > 0) { 
         for (int i = d + 3; i < d + 6; i++) { 
             if (s.recipe[i]->cookAbility.bake > 0) {   //烤
                 strictRule[i]->baseRule.buff += 50; 
             } 
         } 
     }
     if (s.recipe[d + 0]->cookAbility.boil > 0 &&  //煮
         s.recipe[d + 1]->cookAbility.boil > 0 && 
         s.recipe[d + 2]->cookAbility.boil > 0) { 
         for (int i = d + 3; i < d + 6; i++) { 
             if (s.recipe[i]->cookAbility.fry > 0) {   //炸
                 strictRule[i]->baseRule.buff += 50; 
             } 
         } 
     }
     for (int i = d + 0; i < d + 3; i++) {   //第一轮
         if (s.recipe[i]->flavor.sweet) {  //甜
            lenientRule[i]->addRule.buff += 100;  //售价%
             break; 
         } 
     }
     for (int i = d + 3; i < d + 6; i++) {   //第二轮
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 5) {   //传
            lenientRule[i]->baseRule.buff += 50;  //基础售价%
             break; 
         } 
     }
     lenientRule[d + 4]->addRule.full += -3; //饱腹值
     for (int i = d + 3; i < d + 5; i++) {   //第二轮
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 2) {   //优
            lenientRule[i+1]->oneMore();  //意图生效次数
             break; 
         } 
     }
     for (int i = d + 3; i < d + 6; i++) {   //第二轮
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 4) {   //神
            lenientRule[i]->addRule.buff += 100;  //售价%
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
         if (s.recipe[i]->flavor.bitter) {   //苦
            lenientRule[i]->addRule.full += -4;  //饱腹值
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
         if (s.recipe[i]->flavor.sweet) {  //甜
            lenientRule[i]->addRule.buff += 100;  //售价%
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
        if (s.recipe[i]->rarity == 1) {   //一火菜
            lenientRule[i]->baseRule.buff += 50;  //基础售价%
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 5) {   //传
            lenientRule[i]->oneMore();  //意图生效次数
             break; 
         } 
     }
    return 12; 
 }
 int banquetRule1(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank) { 
     int d = rank * DISH_PER_CHEF * CHEFS_PER_GUEST;
     if (s.recipe[d + 0]->cookAbility.bake > 0 &&  //烤
         s.recipe[d + 1]->cookAbility.bake > 0 && 
         s.recipe[d + 2]->cookAbility.bake > 0) { 
         for (int i = d + 3; i < d + 6; i++) {  //下一阶段
             if (s.recipe[i]->cookAbility.knife > 0) {   //切
                strictRule[i]->addRule.buff += 100; //售价
             } 
         } 
     }
     if (s.recipe[d + 0]->cookAbility.fry > 0 &&  //炸
         s.recipe[d + 1]->cookAbility.fry > 0 && 
         s.recipe[d + 2]->cookAbility.fry > 0) { 
         for (int i = d + 3; i < d + 6; i++) {  //下一阶段
             if (s.recipe[i]->cookAbility.boil > 0) {   //煮
                strictRule[i]->addRule.buff += 100; //售价
             } 
         } 
     }
     for (int i = d + 0; i < d + 3; i++) {   //第一轮
         if (s.recipe[i]->flavor.tasty) {   //鲜
            lenientRule[i]->addRule.buff += -150;  //售价%
             break; 
         } 
     }
     for (int i = d + 0; i < d + 3; i++) {   //第一轮
         if (s.recipe[i]->flavor.salty) {   //咸
            lenientRule[i]->addRule.buff += -150;  //售价%
             break; 
         } 
     }
     for (int i = d + 3; i < d + 5; i++) {   //第二轮
        if (s.recipe[i]->cookAbility.knife > 0) {   //切
             if (s.recipe[i+1]->flavor.spicy) {   //辣
                lenientRule[i+1]->baseRule.buff += 50;  //基础售价%
                 break; 
             } 
             break;
         } 
     }
     for (int i = d + 3; i < d + 5; i++) {   //第二轮
        if (s.recipe[i]->cookAbility.boil > 0) {   //煮
         if (s.recipe[i+1]->flavor.sour) {   //酸
                lenientRule[i+1]->baseRule.directAdd += 200; //基础售价数值
                 break; 
             } 
             break;
         } 
     }
     for (int i = d + 3; i < d + 5; i++) {   //第二轮
         if (s.recipe[i]->flavor.spicy) {   //辣
            if (s.recipe[i+1]->cookAbility.boil > 0) {   //煮
                lenientRule[i+1]->addRule.buff += 100;  //售价%
                 break; 
             } 
             break;
         } 
     }
     for (int i = d + 3; i < d + 6; i++) {   //第二轮
         if (s.recipe[i]->flavor.sour) {   //酸
            lenientRule[i]->addRule.buff += 100;  //售价%
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
         if (s.recipe[i]->flavor.tasty) {   //鲜
            lenientRule[i]->addRule.full += 2;  //饱腹值
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
        if (s.recipe[i]->cookAbility.bake > 0) {   //烤
            lenientRule[i]->baseRule.buff += 50;  //基础售价%
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
         if (s.recipe[i]->flavor.salty) {   //咸
            lenientRule[i]->addRule.full += 2;  //饱腹值
             break; 
         } 
     }
     for (int i = d + 6; i < d + 9; i++) {   //第三轮
        if (s.recipe[i]->cookAbility.fry > 0) {   //炸
            lenientRule[i]->addRule.buff += 100;  //售价%
             break; 
         } 
     }
    return 30; 
 } 
#endif
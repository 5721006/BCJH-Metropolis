#ifndef RULE_HPP
#define RULE_HPP
#include "Calculator.hpp"
#include "functions.hpp"
int banquetRule0(BanquetStrictRule **, BanquetLenientRule **, States &, int);
int banquetRule1(BanquetStrictRule **, BanquetLenientRule **, States &, int);

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

//贵客一
int banquetRule0(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank) {
    int d = rank * DISH_PER_CHEF * CHEFS_PER_GUEST;
    for (int i = d + 0; i < d + 3; i++) { 
         if (skill[i / 3].ability / s.recipe[i]->cookAbility >= 5) { 
             lenientRule[i]->oneMore(); 
             break; 
         } 
     } 
     // 条件：蒸 
     // 效果：本道料理售价+100% 
     for (int i = d + 0; i < d + 3; i++) { 
         if (s.recipe[i]->cookAbility.steam) { 
             lenientRule[i]->addRule.buff += 100; 
             break; 
         } 
     } 
     // 条件：鲜 
     // 效果：本道料理饱腹感+2 
     for (int i = d + 0; i < d + 3; i++) { 
         if (s.recipe[i]->flavor == TASTY) { 
             lenientRule[i]->addRule.full += 2; 
             break; 
         } 
     } 
     // 条件：三道炒 
     // 效果：下阶段烤技法料理售价+100% 
     if (s.recipe[d + 0]->cookAbility.stirfry && 
         s.recipe[d + 1]->cookAbility.stirfry && 
         s.recipe[d + 2]->cookAbility.stirfry) { 
         for (int i = d + 3; i < d + 6; i++) { 
             if (s.recipe[i]->cookAbility.bake) { 
                 strictRule[i]->addRule.buff += 100; 
             } 
         } 
     } 
  
     // 第2轮 
     // 条件：酸 
     // 效果：本道料理基础售价+50% 
     for (int i = d + 3; i < d + 6; i++) { 
         if (s.recipe[i]->flavor == SOUR) { 
             lenientRule[i]->baseRule.buff += 50; 
             break; 
         } 
     } 
     // 条件：1火 
     // 效果：本道料理基础售价+300 
     for (int i = d + 3; i < d + 6; i++) { 
         if (s.recipe[i]->rarity == 1) { 
             lenientRule[i]->baseRule.directAdd += 300; 
             break; 
         } 
     } 
     // 条件：三道烤 
     // 效果：下阶段炸技法料理售价+50% 
     if (s.recipe[d + 3]->cookAbility.bake && 
         s.recipe[d + 4]->cookAbility.bake && 
         s.recipe[d + 5]->cookAbility.bake) { 
         for (int i = d + 6; i < d + 9; i++) { 
             if (s.recipe[i]->cookAbility.fry) { 
                 strictRule[i]->addRule.buff += 50; 
             } 
         } 
     } 
     // 条件：煮 
     // 效果：本道料理饱腹感+2 
     for (int i = d + 3; i < d + 6; i++) { 
         if (s.recipe[i]->cookAbility.boil) { 
             lenientRule[i]->addRule.full += 2; 
             break; 
         } 
     } 
  
     // 第3轮 
     // 条件：炒 
     // 效果：本道料理售价-150% 
     for (int i = d + 6; i < d + 9; i++) { 
         if (s.recipe[i]->cookAbility.stirfry) { 
             lenientRule[i]->addRule.buff += -150; 
             break; 
         } 
     } 
     // 条件：煮 
     // 效果：本道料理售价-150% 
     for (int i = d + 6; i < d + 9; i++) { 
         if (s.recipe[i]->cookAbility.boil) { 
             lenientRule[i]->addRule.buff += -150; 
             break; 
         } 
     } 
     // 条件：神 
     // 效果：本道料理基础售价+300 
     for (int i = d + 6; i < d + 9; i++) { 
         if (skill[i / 3].ability / s.recipe[i]->cookAbility >= 4) { 
             lenientRule[i]->baseRule.directAdd += 300; 
             break; 
         } 
     } 
     // 条件：4火 
     // 效果：本道料理售价+100% 
     for (int i = d + 6; i < d + 9; i++) { 
         if (s.recipe[i]->rarity == 4) { 
             lenientRule[i]->addRule.buff += 100; 
             break; 
         } 
     } 
     return 20; 
 }
//贵客二
int banquetRule1(BanquetStrictRule **strictRule, BanquetLenientRule **lenientRule, States &s, int rank) {
    int d = rank * DISH_PER_CHEF * CHEFS_PER_GUEST;

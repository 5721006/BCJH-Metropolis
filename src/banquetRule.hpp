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
     for (int i = d + 3; i < d + 6; i++) {   //第二轮
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 5) {   //传
            lenientRule[i]->baseRule.buff += 50;  //基础售价%
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
        if (s.recipe[i]->rarity == 1) {   //一火菜
            lenientRule[i]->baseRule.buff += 50;  //基础售价%
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
        if (s.chef[i/3]->skill.ability / s.recipe[i]->cookAbility >= 5) {   //传
            lenientRule[i]->oneMore();  //意图生效次数
             break; 
         } 
     }
     for (int i = d + 0; i < d + 6; i++) { 
         if (s.chef[i]->name == "藻白") {    // 藻白下位+10%基售
             lenientRule[i+3]->baseRule.buff += 10; 
         } 
     }
     for (int i = d + 0; i < d + 9; i++) { 
         if (s.chef[i]->name == "姒露") {    // 姒露三火菜+20%售价
            if (s.recipe[i]->rarity == 3) {   //三火菜
                 lenientRule[i]->addRule.buff += 20;  //售价%
             } 
         } 
     }
     for (int i = d + 0; i < d + 9; i++) { 
         if (s.chef[i]->name == "橙风") {    // 橙风三火菜+20%售价
            if (s.recipe[i]->rarity == 3) {   //三火菜
                 lenientRule[i]->addRule.buff += 20;  //售价%
             } 
         } 
     }
     for (int i = d + 0; i < d + 9; i++) { 
         if (s.chef[i]->name == "东华") {    // 东华三火菜+20%售价
            if (s.recipe[i]->rarity == 3) {   //三火菜
                 lenientRule[i]->addRule.buff += 20;  //售价%
             } 
         } 
     }
    return 12; 
 }
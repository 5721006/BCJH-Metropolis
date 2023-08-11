#ifndef TOOLEQUIPPED_HPP
#define TOOLEQUIPPED_HPP
#include "src/Chef.hpp"
#include "src/Values.hpp"

void toolEquipped(Chef *chef) {

    auto skill = &chef->skill;

    if (chef->name == "凯丽") {    // 鎏金之锋
        skill->ability.knife += 150; // 切技法+150
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "宋书汐汐") {    // 凤尾扫把
        skill->materialBuff.vegetable += 20; // 蔬菜售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
   
    if (chef->name == "姒露") {    // 金风扇
        skill->materialBuff.meat += 20; // 肉售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "藻白") {    // 金刚磨刀钢
        skill->abilityBuff.knife += 20; // 切类售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }  

    if (chef->name == "息夫人") {    // 金玉勺
        skill->abilityBuff.boil += 20; // 煮售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "黑柏") {    // 银制剪刀
        skill->ability.knife += 80; // 切技法+80
        skill->materialBuff.fish += 10; // 水产售价+10%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "拉琪") {    // 甜品木托
        skill->abilityBuff.knife += 10; // 切售价+10%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "煎饼") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 101;
        skill->ability.boil += 37;
        skill->ability.knife += 6;
        skill->ability.fry += 38;
        skill->ability.bake += 52;
        skill->ability.steam += 8;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "玄离") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 32;
        skill->ability.boil += 81;
        skill->ability.knife += 56;
        skill->ability.fry += 7;
        skill->ability.bake += 5;
        skill->ability.steam += 21;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "龙波儿") {    // 银制水壶
        skill->ability.boil += 80; // 煮技法+80
        skill->materialBuff.fish += 10; // 水产售价+10%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "府先生") {    // 心声麦克风
        skill->abilityBuff.knife += 20; // 切售价+20%
        skill->materialBuff.vegetable += 15; // 菜售价+15%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "樊欣") {    // 贵族私家托盘
        skill->ability.bake += 90; // 烤技法+90
        skill->abilityBuff.boil += 10; // 煮售价+10%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "郑国民父女") {    // 金印大碗
        skill->abilityBuff.fry += 20; // 炸售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "兰染") {    // 金猫筷子架
        skill->ability.fry += 150; // 炸技法+150
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "尖椒鸡") {    // 反重力酒提
        skill->ability.bake += 150; // 烤技法+150
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "朱悌") {   //御用饭勺
        skill->ability.steam += 150; // 蒸技法+150
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    if (chef->name == "毛太郎") {    // 传世秘籍
        skill->ability.add(40); // 全技法+40
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "鼬名人") {    // 银骰子
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "蜜桃桃") {    // 银骰子
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "羽十六") {    // 传世秘籍
        skill->ability.add(40); // 全技法+40
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    
    if (chef->name == "珍艾") {    // 传世秘籍
        skill->ability.add(40); // 全技法+40
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }

    return; // 以下为示例代码，可自行修改。完成后注释此行。

}
#endif

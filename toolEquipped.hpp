#ifndef TOOLEQUIPPED_HPP
#define TOOLEQUIPPED_HPP
#include "src/Chef.hpp"
#include "src/Values.hpp"

void toolEquipped(Chef *chef) {

    auto skill = &chef->skill;

    if (chef->name == "执笔人") {    // 雾驾陨*3
        skill->abilityBuff.steam += 36; // 蒸类售价+36%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "东华") {    // 金塞醒酒壶+月异陨+席丰玉
        skill->abilityBuff.boil += 30; // 煮类售价+30%
        skill->flavorBuff.tasty += 12; // 鲜售价+12%
        skill->flavorBuff.sour += 12; // 酸售价+12%
        skill->coinBuff += 10; // 1-4菜谱上限+5（伪）
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "乐乐妹") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 12;
        skill->ability.boil += 76;
        skill->ability.knife += 111;
        skill->ability.fry += 13;
        skill->ability.bake += 44;
        skill->ability.steam += 28;
        skill->coinBuff += 10; // 菜谱基础售价+10%（伪）
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "拉琪") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 12;
        skill->ability.boil += 48;
        skill->ability.knife += 113;
        skill->ability.fry +=13;
        skill->ability.bake += 27;
        skill->ability.steam += 62;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "藻白") {    // 巧克力生日帽
        skill->ability.stirfry += 200;
        skill->ability.boil += -50;
        skill->ability.bake += -50;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "橙风") {    // 嘻嘻蜡烛+焦焦陨
        skill->ability.bake += 62; //烤技法+13%
        skill->abilityBuff.bake += 30; // 烤类售价+30%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "达浪") {    // 彩色滚筒刷
        skill->ability.stirfry += 200;
        skill->ability.fry += -50;
        skill->ability.bake += -50;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "姒露") {    // 嘻嘻蜡烛+万斩玉+蜜蜜玉
        skill->abilityBuff.bake += 30; // 烤类售价+30%
        skill->abilityBuff.knife += 8; // 切类售价+8%
        skill->flavorBuff.sweet += 8; // 甜售价+8%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "黑柏") {    // 沸海陨
        skill->ability.knife += -50;
        skill->ability.bake += -50;
        skill->ability.steam += 200;
        skill->abilityBuff.boil += 4; // 煮售价+4%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "煎饼") {    // 闪亮夜视镜
        skill->ability.boil += -50;
        skill->ability.fry += 200;
        skill->ability.steam += -50;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "宋书汐汐") {    // 凤尾扫把
        skill->materialBuff.vegetable += 20; // 蔬菜售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "麦田姬") {  
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "泡泡") {    // 烤官架
        skill->ability.stirfry += 75; // 炒技法+75
        skill->ability.steam += 75; // 蒸技法+75
        skill->materialBuff.fish += 15; // 水产售价+15%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "息夫人") {    // 金玉勺
        skill->abilityBuff.boil += 20; // 煮售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "玄一") {    // 水晶透明菜罩
        skill->ability.fry += 150; // 炸技法+150
        skill->abilityBuff.stirfry += 20; // 炒类售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "玄离") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 37;
        skill->ability.boil += 85;
        skill->ability.knife += 61;
        skill->ability.fry += 13;
        skill->ability.bake += 10;
        skill->ability.steam += 24;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "莫邪") {    // 云驰陨
        skill->ability.boil += 43; // 蒸技法+11%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "府先生") {    // 心声麦克风
        skill->abilityBuff.knife += 20; // 切售价+20%
        skill->materialBuff.vegetable += 15; // 菜售价+15%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    return; // 以下为示例代码，可自行修改。完成后注释此行。
}
#endif
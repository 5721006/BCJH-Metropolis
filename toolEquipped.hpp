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
    if (chef->name == "唐三三") {    // 金塞醒酒壶
        skill->abilityBuff.boil += 30; // 煮类售价+30%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "东华") {    // 金塞醒酒壶+月异陨*2
        skill->abilityBuff.boil += 30; // 煮类售价+30%
        skill->flavorBuff.tasty += 24; // 鲜售价+24%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "玄一") {    // 水晶透明菜罩
        skill->ability.fry += 150; // 炸技法+150
        skill->abilityBuff.stirfry += 20; // 炒类售价+20%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "姒露") {    // 嘻嘻蜡烛+万斩玉+蜜蜜玉+鲸吸陨
        skill->abilityBuff.bake += 30; // 烤类售价+30%
        skill->abilityBuff.knife += 8; // 切类售价+8%
        skill->flavorBuff.sweet += 8; // 甜售价+8%
        skill->flavorBuff.salty += 12; // 咸售价+12%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "橙风") {    // 嘻嘻蜡烛
        skill->abilityBuff.bake += 30; // 烤类售价+30%
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "息夫人") {    // 金玉勺
        skill->abilityBuff.boil += 20; // 煮售价+20%
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
    if (chef->name == "达浪") {    // 彩色滚筒刷
        skill->ability.stirfry += 200;
        skill->ability.fry += -50;
        skill->ability.bake += -50;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "藻白") {    // 巧克力生日帽
        skill->ability.stirfry += 200;
        skill->ability.boil += -50;
        skill->ability.bake += -50;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "乐乐妹") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 11;
        skill->ability.boil += 74;
        skill->ability.knife += 108;
        skill->ability.fry += 10;
        skill->ability.bake += 40;
        skill->ability.steam += 27;
        skill->coinBuff += 10; // 菜谱基础售价+10%（伪）
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "拉琪") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 10;
        skill->ability.boil += 41;
        skill->ability.knife += 110;
        skill->ability.fry += 9;
        skill->ability.bake += 24;
        skill->ability.steam += 60;
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "玄离") {    // 霞姬霸捣药罐
        skill->ability.stirfry += 35;
        skill->ability.boil += 82;
        skill->ability.knife += 59;
        skill->ability.fry += 9;
        skill->ability.bake += 7;
        skill->ability.steam += 22;
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
    if (chef->name == "祖冲之") {   //御用饭勺
        skill->ability.steam += 150; // 蒸技法+150
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "蜜桃桃") {    // 传世秘籍
        skill->ability.add(40);
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "毛太郎") {    // 传世秘籍
        skill->ability.add(40);
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "鼬名人") {    // 传世秘籍
        skill->ability.add(40);
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "苍胡颉") {    // 传世秘籍
        skill->ability.add(40);
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "盐如玉") { 
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    if (chef->name == "麦田姬") {  
        chef->tool = NO_TOOL;          // 不允许装备其他厨具
    }
    return; // 以下为示例代码，可自行修改。完成后注释此行。
}
#endif

#ifndef CONFIG_HPP
#define CONFIG_HPP

#define NUM_GUESTS 2
#define DISH_PER_CHEF 3
#define CHEFS_PER_GUEST 3
#define NUM_CHEFS (NUM_GUESTS * CHEFS_PER_GUEST)

#define MODE 1 // 1:宴会模式; 2:限时任务
#define TARGET_SCORE_APPROXIMATE 3238000

#define ITER_CHEF 2000   // 选择厨师时的迭代次数
#define ITER_RECIPE 3000 // 对于每一组厨师，选择菜谱时的迭代次数

#define AVOID_CHEF_1 true
#define AVOID_CHEF_2 true // 计算时不考虑二火厨师
#define AVOID_CHEF_3 false

#define T_MAX_CHEF TARGET_SCORE_APPROXIMATE / 100 // 选择厨师时的初始温度
#define T_MAX_RECIPE                                                           \
    TARGET_SCORE_APPROXIMATE / 300 // 对于每一组厨师，选择菜谱时的初始温度

// ************************************* //
// ** 以下内容不要修改，会造成程序出问题 ** //
// ************************************* //

#if MODE == 2
#define SEARCH_TARGET_SCORE                                                    \
    TARGET_SCORE_APPROXIMATE // 限时任务时，达到这个分数就可以停止搜索
#endif

#endif

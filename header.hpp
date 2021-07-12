// To remove annoying red wavy lines in VSCODE
// ██╗     ███████╗███████╗████████╗ ██████╗ ██████╗ ██████╗ ███████╗
// ██║     ██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔═══██╗██╔══██╗██╔════╝
// ██║     █████╗  █████╗     ██║   ██║     ██║   ██║██║  ██║█████╗
// ██║     ██╔══╝  ██╔══╝     ██║   ██║     ██║   ██║██║  ██║██╔══╝
// ███████╗███████╗███████╗   ██║   ╚██████╗╚██████╔╝██████╔╝███████╗
// ╚══════╝╚══════╝╚══════╝   ╚═╝    ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝

//  ___      ___       __      ___      ___        ______  ___  ___   __          __
// |"  \    /"  |     /""\    |"  |    |"  |      /    " \|"  \/"  | |" \        /""\     
//  \   \  //   |    /    \   ||  |    ||  |     // ____  \\   \  /  ||  |      /    \    
//  /\\  \/.    |   /' /\  \  |:  |    |:  |    /  /    ) :)\\  \/   |:  |     /' /\  \   
// |: \.        |  //  __'  \  \  |___  \  |___(: (____/ // /\.  \   |.  |    //  __'  \  
// |.  \    /:  | /   /  \\  \( \_|:  \( \_|:  \\        / /  \   \  /\  |\  /   /  \\  \ 
// |___|\__/|___|(___/    \___)\_______)\_______)\"_____/ |___/\___|(__\_|_)(___/    \___)

#include <iostream>
#include <ios>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
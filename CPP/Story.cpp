#include "../Header/Dungeon.h"
#include <random>
void Story()
{
    string line;
    ofstream(file);
    file.open("Files/Battle Records.txt");
    file << "Race            HP       Level    PlayerHP      PlayerLevel       Defeated" << endl;
    file.close();
    srand(time(NULL));
    Dungeon Za_Wordo;
    Player Merlin;
    cout << "Welcome To The Begiening Of Your Journey\nStep Forward now. Do not fear\nShow why you were chosen and They were not\n";
    Merlin = Za_Wordo.Dungeon_Floor_1.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Little Worm Who died without even knowing there was a sky above the sky.\nFall\n";
        exit(0);
    }
    cout << "You who has passed the but the barest of Challanges\nWalk On";
    cout << "Keep walking forward\n";
    Merlin = Za_Wordo.Dungeon_Floor_2.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "You felt it didn't you\nYou felt the very essence of this world aid you in your endeavours\n"
             << "and yet here you fall\nPaThEtIc\n ";
        exit(0);
    }
    cout << "Ah!\nYEs\nThe stage is now set\nAs unlikely as it is I hope you do not die so quickly\nHow dissapointing That would be\n";
    Merlin = Za_Wordo.Dungeon_Floor_3.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Dissapointing\n";
        exit(0);
    }
    cout << "Hmm!?\n";
    Merlin = Za_Wordo.Dungeon_Floor_4.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "True Power Awaits Those Who Strive For It\nSafe To Say\nIt Does Not Await You\n";
        exit(0);
    }
    cout << "Sometimes the world spawns truly glamerous souls.\nThey Burn not with Power nor with Strength\n"
         << "Nor are they born with gifts that put them ahead\nNeigh They are born with a potential to grow\n"
         << "Very rarely though they do\nAre you one of those that does? Or Are you not\n";
    Merlin = Za_Wordo.Dungeon_Floor_5.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Alas!\nAnother Failed Product\n";
        exit(0);
    }
    cout << "Those Glamerous Souls That Preserve through life\nBurn Brighter Then any sun\nTruly it is quite a thing\n"
         << "To witness a miracle in the making\n";
    Merlin = Za_Wordo.Dungeon_Floor_6.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Giant: Listen Well\nI am He who stands\nNot he who stood\nI stood strong against the king of the neather\n"
             << "So i ask\nWho are You to make me fall\n";
        exit(0);
    }
    cout << "Giant: To make me bleed is to do what thousands before you have done\nTo make me kneel is to do what none has done before you\n"
         << "I as The king of Giants as The General of Red Sands as One of The 4 Guadians\nI Deem You Worthy\n";
    Merlin = Za_Wordo.Dungeon_Floor_7.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Shining One: You are just like me\n"
             << "A failure\n";
        exit(0);
    }
    cout << "Glamerous Soul: Stars That Burn too Bright may just go out\nBut those that dont will be snuffed out\n"
    <<"So burn brighter then it is possible to burn\nShow Why You were chosen\n";

    Merlin = Za_Wordo.Dungeon_Floor_8.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Medusa: I was Promised A Worthy Oponent\nYet I Find A child\nTurn to Stone And Shatter\n";
        exit(0);
    }
    Merlin = Za_Wordo.Dungeon_Floor_9.Traverse_Rooms(Merlin);
    cout << "Medusa: Impossible\nTo look at me and not turn to stone\nWhat are you?\n";
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Dragon: Only those Who know the truth may face me and live\nYou do not\n";
        exit(0);
    }
    cout << "Dragon: When You are faced with the undeinable truth\nWill You bend and break\n"
         << "Or Will you accept It For What it truly is\nMomento Mori\nRemember Death\nFor it shall be Your one and Only Companion\n";
    Merlin = Za_Wordo.Dungeon_Floor_10.Traverse_Rooms(Merlin);
    if (Merlin.get_current_hp() == 0)
    {
        cout << "Nether King: Truly A Mystery This One Isn't it\n";
    }
    cout << "Boogy Man: I was Known as the boogy Man\nThe one who haunted the children\nThe one who hid in the closet\nThe One under the Bed"
         << " Where they slept\nThe monster in the dark they warned their parents about\nI remember every child\nI remember Their Hopes\n"
         << "Their dreams\nYet Why\nOh Why do i not remember you in any one of my memories\nGo forward then\n"
         << "O Forgotten One\n";
}
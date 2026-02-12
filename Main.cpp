#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; 

string pickRandom(const string arr[], int size)
{
    int index = rand() % size;
    return arr[index];
}

void showMainMenu()
{
    cout << "\n==== Outfit Picker ====\n";
    cout << "1) Pick a style + generate 1 outfit\n";
    cout << "2) Pick a style + generate 3 outfits\n";
    cout << "3) Exit\n";
}

void showStyleMenu()
{
    cout << "\nPick a style:\n";
    cout << "1) Casual\n";
    cout << "2) Dressy\n";
    cout << "3) Cozy\n";
    cout << "4) Rocker\n";
    cout << "5) Goth\n";
    cout << "Enter style (1-5): ";
}

int getNumbersBetween(int minVal, int maxVal)
{
    int n;
    cin >> n;

    while (cin.fail() || n < minVal || n > maxVal)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter a number (" << minVal << "-" << maxVal << "): ";
        cin >> n;
    }
    return n;
}

void generateOutfits(int styleChoice, int howMany)
{
    // CASUAL arrays
    const int CAS_TOPS = 5, CAS_BOTTOMS = 5, CAS_SHOES = 5;
    string casualTops[CAS_TOPS] = {"black t-shirt", "graphic tee", "tank top", "button-up", "cropped hoodie"};
    string casualBottoms[CAS_BOTTOMS] = {"jeans", "shorts", "cargo pants", "black leggings", "denim skirt"};
    string casualShoes[CAS_SHOES] = {"sneakers", "converse", "slides", "vans", "platform sneakers"};

    // DRESSY arrays
    const int DR_TOPS = 5, DR_BOTTOMS = 5, DR_SHOES = 5;
    string dressyTops[DR_TOPS] = {"silky blouse", "turtleneck", "lace top", "fitted top", "wrap blouse"};
    string dressyBottoms[DR_BOTTOMS] = {"slacks", "midi skirt", "dress pants", "pencil skirt", "wide-leg pants"};
    string dressyShoes[DR_SHOES] = {"heels", "ankle boots", "flats", "loafers", "strappy sandals"};

    // COZY arrays
    const int COZ_TOPS = 5, COZ_BOTTOMS = 5, COZ_SHOES = 5;
    string cozyTops[COZ_TOPS] = {"oversized hoodie", "chunky sweater", "cardigan", "crewneck sweatshirt", "long sleeve tee"};
    string cozyBottoms[COZ_BOTTOMS] = {"sweatpants", "leggings", "soft joggers", "comfy shorts", "pajama pants"};
    string cozyShoes[COZ_SHOES] = {"fuzzy socks", "slippers", "sneakers", "ugg-style boots", "slides"};

    // ROCKER arrays
    const int ROCK_TOPS = 5, ROCK_BOTTOMS = 5, ROCK_SHOES = 5;
    string rockerTops[ROCK_TOPS] = {"band tee", "leather jacket", "ripped hoodie", "denim jacket", "black tank top"};
    string rockerBottoms[ROCK_BOTTOMS] = {"ripped jeans", "black skinny jeans", "cargo pants", "leather pants", "dark denim"};
    string rockerShoes[ROCK_SHOES] = {"combat boots", "high-top sneakers", "chunky boots", "converse", "platform boots"};

    // GOTH arrays
    const int GOTH_TOPS = 5, GOTH_BOTTOMS = 5, GOTH_SHOES = 5;
    string gothTops[GOTH_TOPS] = {"black lace top", "mesh long sleeve", "corset-style top", "oversized black sweater", "turtleneck"};
    string gothBottoms[GOTH_BOTTOMS] = {"black skirt", "fishnet tights + shorts", "black wide-leg pants", "pleated skirt", "black leggings"};
    string gothShoes[GOTH_SHOES] = {"platform boots", "combat boots", "chunky loafers", "pointed flats", "doc-style boots"};

    string styleName;

    for (int i = 1; i <= howMany; i++)
    {
        string top, bottom, shoe;

        switch (styleChoice)
        {
            case 1: // Casual
                styleName = "Casual";
                top = pickRandom(casualTops, CAS_TOPS);
                bottom = pickRandom(casualBottoms, CAS_BOTTOMS);
                shoe = pickRandom(casualShoes, CAS_SHOES);
                break;

            case 2: // Dressy
                styleName = "Dressy";
                top = pickRandom(dressyTops, DR_TOPS);
                bottom = pickRandom(dressyBottoms, DR_BOTTOMS);
                shoe = pickRandom(dressyShoes, DR_SHOES);
                break;

            case 3: // Cozy
                styleName = "Cozy";
                top = pickRandom(cozyTops, COZ_TOPS);
                bottom = pickRandom(cozyBottoms, COZ_BOTTOMS);
                shoe = pickRandom(cozyShoes, COZ_SHOES);
                break;

            case 4: // Rocker
                styleName = "Rocker";
                top = pickRandom(rockerTops, ROCK_TOPS);
                bottom = pickRandom(rockerBottoms, ROCK_BOTTOMS);
                shoe = pickRandom(rockerShoes, ROCK_SHOES);
                break;

            case 5: // Goth
                styleName = "Goth";
                top = pickRandom(gothTops, GOTH_TOPS);
                bottom = pickRandom(gothBottoms, GOTH_BOTTOMS);
                shoe = pickRandom(gothShoes, GOTH_SHOES);
                break;
        }

        if (howMany > 1)
            cout << "\nOption " << i << " (" << styleName << "):\n";
        else
            cout << "\nYour outfit (" << styleName << "):\n";

        cout << "- Top: " << top << endl;
        cout << "- Bottom: " << bottom << endl;
        cout << "- Shoes: " << shoe << endl;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int choice;

    do
    {
        showMainMenu();
        cout << "Enter choice (1-3): ";
        choice = getNumberInRange(1, 3);

        switch (choice)
        {
            case 1:
            {
                showStyleMenu();
                int styleChoice = getNumberInRange(1, 5);
                generateOutfits(styleChoice, 1);
                break;
            }

            case 2:
            {
                showStyleMenu();
                int styleChoice = getNumberInRange(1, 5);
                generateOutfits(styleChoice, 3);
                break;
            }

            case 3:
                cout << "\nBye!.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}

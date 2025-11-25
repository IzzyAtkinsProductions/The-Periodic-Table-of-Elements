#pragma once
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <algorithm> 
#include <map>     
#include <unordered_map> 
#include "utils.h"
#include "facts.hpp"
#include "blocks.hpp"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

using str_vec_umap = std::unordered_map<std::string, std::vector<std::string>>;
using vec_str = std::vector<std::string>;
using i8 = char;

const int elementAmt = 118;
const int lowerTop =  760; 
const int lowerBottom =  860; 

enum {
    ANCIENT = -1
};

enum Fields {
    NAME,
    SYMBOL,
    ATOMIC_NUMBER,
    STANDARD_STATE,
    CHEMIICAL_GROUP_BLOCK
};

enum ColorGroup {
    ALKALI_METAL,
    ALKALINE_EARTH_METAL,
    TRANSITION_METAL,
    REACTIVE_NON_METAL,
    POST_TRANSITION_METAL,
    ACTINIDE,
    METALLOID,
    NOBLE_GAS,
    LANTHANIDE,
    UNKNOWN_PROPERTY
};

static std::string chemicalGroups[9] = {
	"Halogen", "Nonmetal", "Metalloid", "Noble Gas", "Lanthanide", "Alkali Metal", 
	"Transition Metal", "Alkaline Earth Metal", "Post-Transition Metal", 
};

static std::string elementFields[13] = {
	"Atomic Number", "Symbol", "Name", "Standard State", "Chemical Group Block", "Atomic Radius", "Atomic Mass",
	"Ionization Energy", "Electronegativity", "Electron Affinity", "Melting Point", "Boiling Point", "Year Discovered"
};

template<typename T>
void EraseIfZero(T arg, vec_str &vec, int idx);
unsigned int GetIndexByArg(vec_str &data, std::string query);

void FindAndReplaceAll(std::string &data, const std::string &match, const std::string &replace);
std::string PrintInfo(
		std::string symbol,
		std::string name, 
		std::string standardState,
		std::string chemicalGroupBlock,
		short yearDiscovered,
		i8 &atomicNumber, 
		int &atomicRadius,
		float &atomicMass,
		float &ionizationenergy,
		float &electronAffinity,
		float &electronegativity,
		float &meltingPoint,
		float &boilingPoint,
		float &density
);


// /**
//  * static struct initialization order.
//  * 
//  * Symbol
//  * Name
//  * Standard State
//  * Chemical Group Block
//  * facts
//  * Year Discovered
//  * Atomic Number
//  * Atomic Radius
//  * Atomic Mass
//  * Ionization Energy
//  * Electron Affiinity
//  * Electronegativity
//  * Melting Point
//  * Boiling Point
//  * Density
//  */
typedef struct PeriodicTable { 
    std::string symbol;
    std::string name;
    std::string standardState;
    std::string chemicalGroupBlock;
    std::vector<std::string> facts;
    short yearDiscovered;
    i8 atomicNumber;
    int atomicRadius;
    float atomicMass;
    float ionizationenergy;
    float electronAffinity;
    float electronegativity;
    float meltingPoint;
    float boilingPoint;
    float density;

    ColorGroup color;
    int xPos;
    int yPos;

    void DisplayInfo();
    void DrawAsciiBlock();

} PeriodicTable;

static struct H : PeriodicTable { 
    H() { 
        symbol = "H"; 
        name = "Hydrogen";
        // facts = hydrogenFacts;
        standardState = "Gas";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = 1776;
        atomicNumber = 1;
        atomicMass = 1.0080f;
        ionizationenergy = 13.598f;
        electronAffinity = 0.754f;
        electronegativity = 2.2f;
        meltingPoint = 13.81f;
        boilingPoint = 20.28f;
        density = 0.00008988f;  
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 10;
        yPos = 10;
}} H;

static struct He : PeriodicTable { 
    He() { 
        symbol = "He";
        name = "Helium";
        // facts = heliumnFacts;
        standardState = "Gas";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = 1868;
        atomicNumber = 2;
        atomicRadius = 140;
        atomicMass = 4.00260f;
        ionizationenergy = 24.587f;
        meltingPoint = 0.95f;
        boilingPoint = 4.22f;
        density = 0.0001785f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 10;
}} He;

static struct Li : PeriodicTable { 
    Li() { 
        symbol = "Li";
        name = "Lithium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1817;
        atomicNumber = 3;
        atomicRadius = 182;
        atomicMass = 7.0f;
        ionizationenergy = 5.392f;
        electronAffinity = 1.57f;
        meltingPoint = 453.65f;
        boilingPoint = 1615;
        density = 0.534f;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 110;
}} Li;

static struct Be : PeriodicTable { 
    Be() { 
        symbol = "Be";
        name = "Beryllium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = 1798;
        atomicNumber = 4;
        atomicRadius = 153;
        atomicMass = 9.012183f;
        ionizationenergy = 9.323f;
        meltingPoint = 1560;
        boilingPoint = 2744;
        density = 1.85f;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 110;
}} Be;

static struct B : PeriodicTable { 
    B() { 
        symbol = "B";
        name = "Boron";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1808;
        atomicNumber = 5;
        atomicRadius = 192;
        atomicMass = 10.81f;
        ionizationenergy = 8.298f;
        electronAffinity = 0.277f;
        electronegativity = 2.04f;
        meltingPoint = 2348;
        boilingPoint = 4273;
        density = 2.37f;
        color = ColorGroup::METALLOID;
        xPos = 1310;
        yPos = 110;
}} B;

static struct C : PeriodicTable { 
    C() { 
        symbol = "C";
        name = "Carbon";
        standardState = "Solid";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = ANCIENT;
        atomicNumber = 6;
        atomicRadius = 170;
        atomicMass = 12.011f;
        ionizationenergy = 11.260f;
        electronAffinity = 1.263f;
        electronegativity = 2.55f;
        meltingPoint = 3823;
        boilingPoint = 4098;
        density = 2.2670f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1410;
        yPos = 110;
}} C;

static struct N : PeriodicTable { 
    N() { 
        symbol = "N";
        name = "Nitrogen";
        standardState = "Gas";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = 1772;
        atomicNumber = 7;
        atomicRadius = 155;
        atomicMass = 14.007f;
        ionizationenergy = 14.534f;
        electronegativity = 3.04f;
        electronAffinity = 7;
        meltingPoint = 63.15f;
        boilingPoint = 77.36f;
        density = 0.0012506f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1510;
        yPos = 110;
}} N;

static struct O : PeriodicTable { 
    O() { 
        symbol = "O";
        name = "Oxygen";
        standardState = "Gas";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = 1774;
        atomicNumber = 8;
        atomicRadius = 152;
        atomicMass = 15.999;
        ionizationenergy = 13.618f;
        electronegativity = 3.44f;
        electronAffinity = 141;
        meltingPoint = 54.36f;
        boilingPoint = 90.2f;
        density = 0.001429f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1610;
        yPos = 110;
}} O;

static struct F : PeriodicTable { 
    F() { 
        symbol = "F";
        name = "Fluorine";
        standardState = "Gas";
        chemicalGroupBlock = "Halogen";
        yearDiscovered = 1670;
        atomicNumber = 9;
        atomicRadius = 135;
        atomicMass = 18.99840316f;
        ionizationenergy = 17.423f;
        electronAffinity = 3.339f;
        electronegativity = 3.98f;
        meltingPoint = 53.53f;
        boilingPoint = 85.03f;
        density = 0.001696f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1710;
        yPos = 110;
}} F;

static struct Ne : PeriodicTable { 
    Ne() { 
        symbol = "Ne";
        name = "Neon";
        standardState = "Gas";
        chemicalGroupBlock = "Noble Gas";
        yearDiscovered = 1898;
        atomicNumber = 10;
        atomicRadius = 154;
        atomicMass = 20.180f;
        ionizationenergy = 21.565f;
        meltingPoint = 24.56f;
        boilingPoint = 27.07f;
        density = 0.0008999f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 110;
}} Ne;


static struct Na : PeriodicTable { 
    Na() { 
        symbol = "Na";
        name = "Sodium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1807;
        atomicNumber = 11;
        atomicRadius = 227;
        atomicMass = 22.9897693f;
        ionizationenergy = 5.139f;
        electronAffinity = 0.548f;
        electronegativity = 0.93f;
        meltingPoint = 370.95f;
        boilingPoint = 1156;
        density = 0.97f;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 210;
}} Na;

static struct Mg : PeriodicTable { 
    Mg() { 
        symbol = "Mg";
        name = "Magnesium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = 1808;
        atomicNumber = 12;
        atomicRadius = 173;
        atomicMass = 24.305f;
        ionizationenergy = 7.646f;
        electronegativity = 1.31f;
        meltingPoint = 923;
        boilingPoint = 1363;
        density = 1.74f;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 210;
}} Mg;

static struct Al : PeriodicTable { 
    Al() { 
        symbol = "Al";
        name = "Aluminum";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 13;
        atomicRadius = 184;
        atomicMass = 26.981538f;
        ionizationenergy = 5.986f;
        electronAffinity = 0.441f;
        electronegativity = 1.61f;
        meltingPoint = 933.437f;
        boilingPoint = 2792;
        density = 2.70f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1310;
        yPos = 210;
}} Al;

static struct Si : PeriodicTable { 
    Si() { 
        symbol = "Si";
        name = "Silicon";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1854;
        atomicNumber = 14;
        atomicRadius = 210;
        atomicMass = 28.085f;
        ionizationenergy = 8.152f;
        electronAffinity = 1.385f;
        electronegativity = 1.9f;
        meltingPoint = 1687;
        boilingPoint = 3538;
        density = 2.3296f;
        color = ColorGroup::METALLOID;
        xPos = 1410;
        yPos = 210;
}} Si;

static struct P : PeriodicTable { 
    P() { 
        symbol = "P";
        name = "Phosphorus";
        standardState = "Solid";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = 1669;
        atomicNumber = 15;
        atomicRadius = 180;
        atomicMass = 30.97376200f;
        ionizationenergy = 10.487f;
        electronAffinity = 0.746f;
        electronegativity = 2.19f;
        meltingPoint = 317.3f;
        boilingPoint = 553.65f;
        density = 1.82f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1510;
        yPos = 210;
}} P;

static struct S : PeriodicTable { 
    S() { 
        symbol = "S";
        name = "Sulfur";
        standardState = "Solid";
        chemicalGroupBlock = "Nonmetal";
        yearDiscovered = ANCIENT;
        atomicNumber = 16;
        atomicRadius = 180;
        atomicMass = 32.07f;
        ionizationenergy = 10.360f;
        electronAffinity = 2.077f;
        electronegativity = 2.58f;
        meltingPoint = 388.36f;
        boilingPoint = 717.75f;
        density = 2.067f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1610;
        yPos = 210;
}} S;

static struct Cl : PeriodicTable { 
    Cl() { 
        symbol = "Cl";
        name = "Chlorine";
        standardState = "Gas";
        chemicalGroupBlock = "Halogen";
        yearDiscovered = 1774;
        atomicNumber = 17;
        atomicRadius = 180;
        atomicMass = 35.45f;
        ionizationenergy = 12.968f;
        electronAffinity = 3.617f;
        electronegativity = 3.16f;
        meltingPoint = 171.65f;
        boilingPoint = 239.11f;
        density = 0.003214f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1710;
        yPos = 210;
}} Cl;

static struct Ar : PeriodicTable { 
    Ar() { 
        symbol = "Ar";
        name = "Chlorine";
        standardState = "Gas";
        chemicalGroupBlock = "Noble Gas";
        yearDiscovered = 1894;
        atomicNumber = 18;
        atomicRadius = 188;
        atomicMass = 39.9f;
        ionizationenergy = 15.760f;
        meltingPoint = 83.8f;
        boilingPoint = 87.3f;
        density = 0.0017837f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 210;
}} Ar;

static struct K : PeriodicTable { 
    K() { 
        symbol = "K";
        name = "Potassium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1774;
        atomicNumber = 19;
        atomicRadius = 275;
        atomicMass = 39.0983f;
        ionizationenergy = 4.341f;
        electronAffinity = 0.501f;
        electronegativity = 0.82f;
        meltingPoint = 336.53f;
        boilingPoint = 1032;
        density = 0.89f;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 310;
}} K;

static struct Ca : PeriodicTable { 
    Ca() { 
        symbol = "Ca";
        name = "Calcium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 20;
        atomicRadius = 231;
        atomicMass = 40.08f;
        ionizationenergy = 6.113f;
        electronegativity = 1;
        electronAffinity = 2.37f;
        meltingPoint = 1115;
        boilingPoint = 1757;
        density = 1.54f;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 310;
}} Ca;

static struct Sc : PeriodicTable { 
    Sc() { 
        symbol = "Sc";
        name = "Scandium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1879;
        atomicNumber = 21;
        atomicRadius = 211;
        atomicMass = 44.95591f;
        ionizationenergy = 6.561f;
        electronAffinity = 0.188f;
        electronegativity = 1.36f;
        meltingPoint = 1814;
        boilingPoint = 3109;
        density = 2.99f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 210;
        yPos = 310;
}} Sc;

static struct Ti : PeriodicTable { 
    Ti() { 
        symbol = "Ti";
        name = "Titanium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1791;
        atomicNumber = 22;
        atomicRadius = 187;
        atomicMass = 47.867f;
        ionizationenergy = 6.828f;
        electronAffinity = 0.079f;
        electronegativity = 1.54f;
        meltingPoint = 1941;
        boilingPoint = 3560;
        density = 4.5f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 410;
        yPos = 310;
}} Ti;

static struct V : PeriodicTable { 
    V() { 
        symbol = "V";
        name = "Vanadium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1801;
        atomicNumber = 23;
        atomicRadius = 179;
        atomicMass = 50.9415;
        ionizationenergy = 6.746f;
        electronAffinity = 0.525f;
        electronegativity = 1.69f;
        meltingPoint = 2183;
        boilingPoint = 3680;
        density = 6.0f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 510;
        yPos = 310;
}} V;

static struct Cr : PeriodicTable { 
    Cr() { 
        symbol = "Cr";
        name = "Chromium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1797;
        atomicNumber = 24;
        atomicRadius = 189;
        atomicMass = 51.996f;
        ionizationenergy = 6.747f;
        electronAffinity = 0.666f;
        electronegativity = 1.66f;
        meltingPoint = 2180;
        boilingPoint = 2944;
        density = 7.15f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 610;
        yPos = 310;
}} Cr;

static struct Mn : PeriodicTable { 
    Mn() { 
        symbol = "Mn";
        name = "Manganese";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1774;
        atomicNumber = 25;
        atomicRadius = 197;
        atomicMass = 54.93804f;
        ionizationenergy = 7.434f;
        electronegativity = 1.66f;
        meltingPoint = 1519;
        boilingPoint = 2334;
        density = 7.3f;
        color = ColorGroup::TRANSITION_METAL;
        xPos =710;
        yPos = 310;
}} Mn;


static struct Fe : PeriodicTable { 
    Fe() { 
        symbol = "Fe";
        name = "Iron";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 26;
        atomicRadius = 194;
        atomicMass = 55.84f;
        ionizationenergy = 7.902f;
        electronAffinity = 0.163f;
        electronegativity = 1.83f;
        meltingPoint = 1811;
        boilingPoint = 3134;
        density = 7.874f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 810;
        yPos = 310;
}} Fe;


static struct Co : PeriodicTable { 
    Co() { 
        symbol = "Co";
        name = "Cobalt";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1735;
        atomicNumber = 27;
        atomicRadius = 192;
        atomicMass = 58.93319f;
        ionizationenergy = 7.881f;
        electronAffinity = 0.661f;
        electronegativity = 1.88f;
        meltingPoint = 1768;
        boilingPoint = 3200;
        density = 8.6f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 910;
        yPos = 310;
}} Co;


static struct Ni : PeriodicTable { 
    Ni() { 
        symbol = "Ni";
        name = "Nickel";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1751;
        atomicNumber = 28;
        atomicRadius = 163;
        atomicMass = 58.693f;
        ionizationenergy = 7.640f;
        electronAffinity = 1.156f;
        electronegativity = 1.91f;
        meltingPoint = 1728;
        boilingPoint = 3186;
        density = 8.912f;
        color = ColorGroup::TRANSITION_METAL;
        xPos =1010;
        yPos = 310;
}} Ni;


static struct Cu : PeriodicTable { 
    Cu() { 
        symbol = "Cu";
        name = "Copper";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 29;
        atomicRadius = 140;
        atomicMass =  63.55;
        ionizationenergy = 7.726f;
        electronAffinity = 1.228f;
        electronegativity = 1.9f;
        meltingPoint = 1357.77;
        boilingPoint = 2835;
        density = 8.833f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1110;
        yPos = 310;
}} Cu;

static struct Zn : PeriodicTable { 
    Zn() { 
        symbol = "Zn";
        name = "Zinc";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1746;
        atomicNumber = 30;
        atomicRadius = 139;
        atomicMass = 65.4f;
        ionizationenergy = 9.394f;
        electronegativity = 1.65f;
        meltingPoint = 692.68f;
        boilingPoint = 1180;
        density = 7.134f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1210;
        yPos = 310;
}} Zn;

static struct Ga : PeriodicTable { 
    Ga() { 
        symbol = "Ga";
        name = "Gallium";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 1875;
        atomicNumber = 31;
        atomicRadius = 187;
        atomicMass = 69.723f;
        ionizationenergy = 5.999f;
        electronAffinity = 0.3f;
        electronegativity = 1.81f;
        meltingPoint = 302.91f;
        boilingPoint = 2477;
        density = 5.91;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1310;
        yPos = 310;
}} Ga;

static struct Ge : PeriodicTable { 
    Ge() { 
        symbol = "Ge";
        name = "Germanium";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1886;
        atomicNumber = 32;
        atomicRadius = 211;
        atomicMass = 72.63f;
        ionizationenergy = 7.900f;
        electronAffinity = 1.35f;
        electronegativity = 2.01f;
        meltingPoint = 1211.4f;
        boilingPoint = 3106;
        density = 5.323;
        color = ColorGroup::METALLOID;
        xPos = 1410;
        yPos = 310;
}} Ge;

static struct As : PeriodicTable { 
    As() { 
        symbol = "As";
        name = "Arsenic";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = ANCIENT;
        atomicNumber = 33;
        atomicRadius = 185;
        atomicMass = 74.92159f;
        ionizationenergy = 9.815f;
        electronAffinity = 0.81f;
        electronegativity = 2.18f;
        meltingPoint = 1090;
        boilingPoint = 887;
        density = 5.776;
        color = ColorGroup::METALLOID;
        xPos = 1510;
        yPos = 310;
}} As;

static struct Se : PeriodicTable { 
    Se() { 
        symbol = "Se";
        name = "Sermanium";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1817;
        atomicNumber = 34;
        atomicRadius = 190;
        atomicMass = 78.97f;
        ionizationenergy = 9.752f;
        electronAffinity = 2.021f;
        electronegativity = 2.55f;
        meltingPoint = 493.65f;
        boilingPoint = 958;
        density = 4.809;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1610;
        yPos = 310;
}} Se;

static struct Br : PeriodicTable { 
    Br() { 
        symbol = "Br";
        name = "Bromine";
        standardState = "Solid";
        chemicalGroupBlock = "Halogen";
        yearDiscovered = 1826;
        atomicNumber = 35;
        atomicRadius = 183;
        atomicMass = 79.90f;
        ionizationenergy = 11.814f;
        electronAffinity = 3.365f;
        electronegativity = 2.96f;
        meltingPoint = 265.95f;
        boilingPoint = 331.95;
        density = 3.11;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1710;
        yPos = 310;
}} Br;

static struct Kr : PeriodicTable { 
    Kr() { 
        symbol = "Kr";
        name = "Kromine";
        standardState = "Solid";
        chemicalGroupBlock = "Halogen";
        yearDiscovered = 1898;
        atomicNumber = 36;
        atomicRadius = 202;
        atomicMass = 83.80f;
        ionizationenergy = 14.000f;
        electronegativity = 3;
        meltingPoint = 115.79f;
        boilingPoint = 119.93f;
        density = 0.003733f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 310;
}} Kr;

static struct Rb : PeriodicTable { 
    Rb() { 
        symbol = "Rb";
        name = "Rubidium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1861;
        atomicNumber = 37;
        atomicRadius = 303;
        atomicMass = 85.468f;
        ionizationenergy = 4.177f;
        electronAffinity = 0.468;
        electronegativity = 0.468;
        meltingPoint = 312.46f;
        boilingPoint = 961;
        density = 1.53f;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 410;
}} Rb;

static struct Sr : PeriodicTable { 
    Sr() { 
        symbol = "Sr";
        name = "Strontium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = 1790;
        atomicNumber = 38;
        atomicRadius = 249;
        atomicMass = 87.62f;
        ionizationenergy = 5.695f;
        electronegativity = 0.95f;
        electronAffinity = 5.03f;
        meltingPoint = 1050;
        boilingPoint = 1655;
        density = 2.64f;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 410;
}} Sr;

static struct Y : PeriodicTable { 
    Y() { 
        symbol = "Y";
        name = "Yttrium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1794;
        atomicNumber = 39;
        atomicRadius = 219;
        atomicMass = 88.90584f;
        ionizationenergy = 6.217f;
        electronAffinity = 0.307f;
        electronegativity = 1.22f;
        meltingPoint = 1795;
        boilingPoint = 3618;
        density = 4.47f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 210;
        yPos = 410;
}} Y;

static struct Zr : PeriodicTable { 
    Zr() { 
        symbol = "Zr";
        name = "Zirconium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1789;
        atomicNumber = 40;
        atomicRadius = 186;
        atomicMass = 91.22f;
        ionizationenergy = 6.634f;
        electronAffinity = 0.426f;
        electronegativity = 1.33f;
        meltingPoint = 2128;
        boilingPoint = 4682;
        density = 6.52f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 410;
        yPos = 410;
}} Zr;

static struct Nb : PeriodicTable { 
    Nb() { 
        symbol = "Nb";
        name = "Niobium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1801;
        atomicNumber = 41;
        atomicRadius = 207;
        atomicMass = 92.90637f;
        ionizationenergy = 6.759f;
        electronAffinity = 0.893f;
        electronegativity = 1.6f;
        meltingPoint = 2750;
        boilingPoint = 5017;
        density = 8.57f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 510;
        yPos = 410;
}} Nb;

static struct Mo : PeriodicTable { 
    Mo() { 
        symbol = "Mo";
        name = "Molybdenum";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1778;
        atomicNumber = 42;
        atomicRadius = 209;
        atomicMass = 95.95f;
        ionizationenergy = 7.092f;
        electronAffinity = 0.746f;
        electronegativity = 2.16f;
        meltingPoint = 2896;
        boilingPoint = 4912;
        density = 10.2f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 610;
        yPos = 410;
}} Mo;

static struct Tc : PeriodicTable { 
    Tc() { 
        symbol = "Tc";
        name = "Technetium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1937;
        atomicNumber = 43;
        atomicRadius = 209;
        atomicMass = 96.90636f;
        ionizationenergy = 7.28f;
        electronAffinity = 0.55f;
        electronegativity = 1.9f;
        meltingPoint = 2430;
        boilingPoint = 4538;
        density = 11;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 710;
        yPos = 410;
}} Tc;

static struct Ru : PeriodicTable { 
    Ru() { 
        symbol = "Ru";
        name = "Ruthenium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1827;
        atomicNumber = 44;
        atomicRadius = 207;
        atomicMass = 101.1f;
        ionizationenergy = 7.361f;
        electronAffinity = 1.05;
        electronegativity = 2.2f;
        meltingPoint = 2607;
        boilingPoint = 4423;
        density = 12.1f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 810;
        yPos = 410;
}} Ru;

static struct Rh : PeriodicTable { 
    Rh() { 
        symbol = "Rh";
        name = "Rhodium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1803;
        atomicNumber = 45;
        atomicRadius = 195;
        atomicMass = 102.9055f;
        ionizationenergy = 7.459f;
        electronAffinity = 1.137f;
        electronegativity = 2.28f;
        meltingPoint = 2237;
        boilingPoint = 3968;
        density = 12.5f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 910;
        yPos = 410;
}} Rh;

static struct Pd : PeriodicTable { 
    Pd() { 
        symbol = "Pd";
        name = "Palladium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1803;
        atomicNumber = 46;
        atomicRadius = 202;
        atomicMass = 106.42f;
        ionizationenergy = 8.337f;
        electronAffinity = 0.557f;
        electronegativity = 2.2f;
        meltingPoint = 1828.05;
        boilingPoint = 3236;
        density = 12.0f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1010;
        yPos = 410;
}} Pd;

static struct Ag : PeriodicTable { 
    Ag() { 
        symbol = "Ag";
        name = "Silver";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 47;
        atomicRadius = 172;
        atomicMass = 107.868f;
        ionizationenergy = 7.576f;
        electronAffinity = 1.302f;
        electronegativity = 1.93f;
        meltingPoint = 1234.93;
        boilingPoint = 2435;
        density = 10.501f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1110;
        yPos = 410;
}} Ag;

static struct Cd : PeriodicTable { 
    Cd() { 
        symbol = "Cd";
        name = "Cadmium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1817;
        atomicNumber = 48;
        atomicRadius = 158;
        atomicMass = 112.41f;
        ionizationenergy = 8.994f;
        electronegativity = 1.699f;
        meltingPoint = 594.22f;
        boilingPoint = 1040;
        density = 8.69f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1210;
        yPos = 410;
}} Cd;

static struct In : PeriodicTable { 
    In() { 
        symbol = "In";
        name = "Indium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1863;
        atomicNumber = 49;
        atomicRadius = 193;
        atomicMass = 114.818f;
        ionizationenergy = 5.786f;
        electronAffinity = 0.3f;
        electronegativity = 1.78f;
        meltingPoint = 429.75f;
        boilingPoint = 2345;
        density = 7.31f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1310;
        yPos = 410;
}} In;

static struct Sn : PeriodicTable { 
    Sn() { 
        symbol = "Sn";
        name = "Tin";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 50;
        atomicRadius = 217;
        atomicMass = 118.71f;
        ionizationenergy = 7.344f;
        electronAffinity = 1.2f;
        electronegativity = 1.96f;
        meltingPoint = 505.08f;
        boilingPoint = 2875;
        density = 7.287f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1410;
        yPos = 410;
}} Sn;

static struct Sb : PeriodicTable { 
    Sb() { 
        symbol = "Sb";
        name = "Antimony";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = ANCIENT;
        atomicNumber = 51;
        atomicRadius = 206;
        atomicMass = 121.760f;
        ionizationenergy = 8.64f;
        electronAffinity = 1.07f;
        electronegativity = 2.05f;
        meltingPoint = 903.78f;
        boilingPoint = 1860;
        density = 6.685f;
        color = ColorGroup::METALLOID;
        xPos = 1510;
        yPos = 410;
}} Sb;

static struct Te : PeriodicTable { 
    Te() { 
        symbol = "Te";
        name = "Tellurium";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1782;
        atomicNumber = 52;
        atomicRadius = 206;
        atomicMass = 127.6f;
        ionizationenergy = 9.010f;
        electronAffinity = 1.971f;
        electronegativity = 2.1f;
        meltingPoint = 722.66f;
        boilingPoint = 1261;
        density = 6.232f;
        color = ColorGroup::METALLOID;
        xPos = 1610;
        yPos = 410;
}} Te;

static struct I : PeriodicTable { 
    I() { 
        symbol = "I";
        name = "Iodine";
        standardState = "Solid";
        chemicalGroupBlock = "Halogen";
        yearDiscovered = 1811;
        atomicNumber = 53;
        atomicRadius = 198;
        atomicMass = 126.9045f;
        ionizationenergy = 10.451f;
        electronAffinity = 3.059f;
        electronegativity = 2.66f;
        meltingPoint = 386.85f;
        boilingPoint = 457.55f;
        density = 4.93f;
        color = ColorGroup::REACTIVE_NON_METAL;
        xPos = 1710;
        yPos = 410;
}} I;

static struct Xe : PeriodicTable { 
    Xe() { 
        symbol = "Xe";
        name = "Xenon";
        standardState = "Gas";
        chemicalGroupBlock = "Noble Gas";
        yearDiscovered = 1898;
        atomicNumber = 54;
        atomicRadius = 216;
        atomicMass = 131.29f;
        ionizationenergy = 12.130f;
        electronegativity = 2.6f;
        meltingPoint = 161.36f;
        boilingPoint = 165.03;
        density = 0.005887f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 410;
}} Xe;

static struct Cs : PeriodicTable { 
    Cs() { 
        symbol = "Cs";
        name = "Cesium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1860;
        atomicNumber = 55;
        atomicRadius = 343;
        atomicMass = 132.9054520f;
        ionizationenergy = 3.894f;
        electronAffinity = 0.472f;
        electronegativity = 2.66f;
        meltingPoint = 301.59f;
        boilingPoint = 944;
        density = 1.93f;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 510;
}} Cs;

static struct Ba : PeriodicTable { 
    Ba() { 
        symbol = "Ba";
        name = "Barium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = 1808;
        atomicNumber = 56;
        atomicRadius = 268;
        atomicMass = 137.33f;
        ionizationenergy = 5.212f;
        electronegativity = 0.89f;
        meltingPoint = 1000;
        boilingPoint = 2170;
        density = 3.62f;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 510;
}} Ba;

static struct La : PeriodicTable { 
    La() { 
        symbol = "La";
        name = "Lanthanum";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1839;
        atomicNumber = 57;
        atomicRadius = 240;
        atomicMass = 138.9055f;
        ionizationenergy = 5.577f;
        electronAffinity = 0.5f;
        electronegativity = 1.1f;
        meltingPoint = 1191;
        boilingPoint = 3737;
        density = 6.15f;
        color = ColorGroup::LANTHANIDE;
        xPos = 210;
        yPos = 510;
}} La;

static struct Ce : PeriodicTable { 
    Ce() { 
        symbol = "Ce";
        name = "Cerium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1803;
        atomicNumber = 58;
        atomicRadius = 235;
        atomicMass = 140.116f;
        ionizationenergy = 5.539f;
        electronAffinity = 0.5f;
        electronegativity = 1.12f;
        meltingPoint = 1071;
        boilingPoint = 3697;
        density = 6.770f;
        color = ColorGroup::LANTHANIDE;
        xPos = 410;
        yPos = lowerTop;
}} Ce;

static struct Pr : PeriodicTable { 
    Pr() { 
        symbol = "Pr";
        name = "Praseodymium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1885;
        atomicNumber = 59;
        atomicRadius = 239;
        atomicMass = 140.90766f;
        ionizationenergy = 5.464f;
        electronAffinity = 0.5f;
        electronegativity = 1.12f;
        meltingPoint = 1204;
        boilingPoint = 3793;
        density = 6.77f;
        color = ColorGroup::LANTHANIDE;
        xPos = 510;
        yPos = lowerTop;
}} Pr;

static struct Nd : PeriodicTable { 
    Nd() { 
        symbol = "Nd";
        name = "Neodymium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1885;
        atomicNumber = 60;
        atomicRadius = 229;
        atomicMass = 144.24f;
        ionizationenergy = 5.525f;
        electronegativity = 1.14f;
        meltingPoint = 1294;
        boilingPoint = 3347;
        density = 7.01f;
        color = ColorGroup::LANTHANIDE;
        xPos = 610;
        yPos = lowerTop;
}} Nd;

static struct Pm : PeriodicTable { 
    Pm() { 
        symbol = "Pm";
        name = "Promethium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1945;
        atomicNumber = 61;
        atomicRadius = 236;
        atomicMass = 144.91276f;
        ionizationenergy = 5.55f;
        meltingPoint = 1315;
        boilingPoint = 3273;
        density = 7.26f;
        color = ColorGroup::LANTHANIDE;
        xPos = 710;
        yPos = lowerTop;
}} Pm;

static struct Sm : PeriodicTable { 
    Sm() { 
        symbol = "Sm";
        name = "Samarium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1879;
        atomicNumber = 62;
        atomicRadius = 229;
        atomicMass = 150.4f;
        ionizationenergy = 5.664f;
        electronegativity = 1.17f;
        meltingPoint = 1347;
        boilingPoint = 2067;
        density = 7.52f;
        color = ColorGroup::LANTHANIDE;
        xPos = 810;
        yPos = lowerTop;
}} Sm;

static struct Eu : PeriodicTable { 
    Eu() { 
        symbol = "Eu";
        name = "Europium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1901;
        atomicNumber = 63;
        atomicRadius = 233;
        atomicMass = 151.964f;
        ionizationenergy = 5.670f;
        meltingPoint = 1095;
        boilingPoint = 1802;
        density = 5.24f;
        color = ColorGroup::LANTHANIDE;
        xPos = 910;
        yPos = lowerTop;
}} Eu;

static struct Gd : PeriodicTable { 
    Gd() { 
        symbol = "Gd";
        name = "Gadolinium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1880;
        atomicNumber = 64;
        atomicRadius = 237;
        atomicMass = 157.2f;
        ionizationenergy = 6.150f;
        meltingPoint = 1586;
        boilingPoint = 3546;
        density = 7.90f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1010;
        yPos = lowerTop;
}} Gd;

static struct Tb : PeriodicTable { 
    Tb() { 
        symbol = "Tb";
        name = "Terbium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1843;
        atomicNumber = 65;
        atomicMass = 158.92535f;
        ionizationenergy = 5.864f;
        electronegativity = 1.17f;
        meltingPoint = 1629;
        boilingPoint = 3503;
        density = 8.23f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1110;
        yPos = lowerTop;
}} Tb;

static struct Dy : PeriodicTable { 
    Dy() { 
        symbol = "Dy";
        name = "Dysprosium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1886;
        atomicNumber = 66;
        atomicRadius = 229;
        atomicMass = 162.500f;
        ionizationenergy = 5.939f;
        electronegativity = 1.22f;
        meltingPoint = 1685;
        boilingPoint = 2840;
        density = 8.55f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1210;
        yPos = lowerTop;
}} Dy;

static struct Ho : PeriodicTable { 
    Ho() { 
        symbol = "Ho";
        name = "Holmium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1878;
        atomicNumber = 67;
        atomicRadius = 217;
        atomicMass = 164.93033f;
        ionizationenergy = 6.022f;
        electronegativity = 1.23f;
        meltingPoint = 1747;
        boilingPoint = 2973;
        density = 8.80f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1310;
        yPos = lowerTop;
}} Ho;

static struct Er : PeriodicTable { 
    Er() { 
        symbol = "Er";
        name = "Erbium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1843;
        atomicNumber = 68;
        atomicRadius = 235;
        atomicMass = 167.26f;
        ionizationenergy = 6.108f;
        electronegativity = 1.24f;
        meltingPoint = 1802;
        boilingPoint = 3141;
        density = 9.07f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1410;
        yPos = lowerTop;
}} Er;

static struct Tm : PeriodicTable { 
    Tm() { 
        symbol = "Tm";
        name = "Thulium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1879;
        atomicNumber = 69;
        atomicRadius = 227;
        atomicMass = 168.93422f;
        ionizationenergy = 6.184f;
        electronegativity = 1.25f;
        meltingPoint = 1818;
        boilingPoint = 2223;
        density = 9.32f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1510;
        yPos = lowerTop;
}} Tm;

static struct Yb : PeriodicTable { 
    Yb() { 
        symbol = "Yb";
        name = "Ytterbium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1878;
        atomicNumber = 70;
        atomicRadius = 242;
        atomicMass = 173.05f;
        ionizationenergy = 6.254f;
        meltingPoint = 1092;
        boilingPoint = 1469;
        density = 6.90f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1610;
        yPos = lowerTop;
}} Yb;

static struct Lu : PeriodicTable { 
    Lu() { 
        symbol = "Lu";
        name = "Lutetium";
        standardState = "Solid";
        chemicalGroupBlock = "Lanthanide";
        yearDiscovered = 1907;
        atomicNumber = 71;
        atomicRadius = 221;
        atomicMass = 174.9668f;
        ionizationenergy = 5.426f;
        electronegativity = 1.27f;
        meltingPoint = 1936;
        boilingPoint = 3675;
        density = 9.84f;
        color = ColorGroup::LANTHANIDE;
        xPos = 1710;
        yPos = lowerTop;
}} Lu;

static struct Hf : PeriodicTable { 
    Hf() { 
        symbol = "Hf";
        name = "Hafnium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1923;
        atomicNumber = 72;
        atomicRadius = 212;
        atomicMass = 178.49f;
        ionizationenergy = 6.825f;
        electronegativity = 1.3f;
        meltingPoint = 2506;
        boilingPoint = 4876;
        density = 13.3f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 410;
        yPos = 510;
}} Hf;

static struct Ta : PeriodicTable { 
    Ta() { 
        symbol = "Ta";
        name = "Tantalum";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1802;
        atomicNumber = 73;
        atomicRadius = 217;
        atomicMass = 180.9479f;
        ionizationenergy = 7.89f;
        electronAffinity = 0.322f; 
        electronegativity = 1.5f;
        meltingPoint = 3290;
        boilingPoint = 5731;
        density = 16.4f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 510;
        yPos = 510;
}} Ta;

static struct W : PeriodicTable { 
    W() { 
        symbol = "W";
        name = "Tungsten";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1783;
        atomicNumber = 74;
        atomicRadius = 210;
        atomicMass = 183.84f;
        ionizationenergy = 7.98f;
        electronAffinity = 0.815f; 
        electronegativity = 2.36f;
        meltingPoint = 3695;
        boilingPoint = 5828;
        density = 19.3f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 610;
        yPos = 510;
}} W;

static struct Re : PeriodicTable { 
    Re(){ 
        symbol = "Re";
        name = "Rhenium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1925;
        atomicNumber = 75;
        atomicRadius = 217;
        atomicMass = 186.207f;
        ionizationenergy = 7.88f;
        electronAffinity = 0.15f; 
        electronegativity = 1.9f;
        meltingPoint = 3459;
        boilingPoint = 5869;
        density = 20.8f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 710;
        yPos = 510;
}} Re;

static struct Os : PeriodicTable { 
    Os(){ 
        symbol = "Os";
        name = "Osmium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1803;
        atomicNumber = 76;
        atomicRadius = 216;
        atomicMass = 190.2f;
        ionizationenergy = 8.7f;
        electronAffinity = 1.1f; 
        electronegativity = 2.2f;
        meltingPoint = 3306;
        boilingPoint = 5285;
        density = 22.57f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 810;
        yPos = 510;
}} Os;

static struct Ir : PeriodicTable { 
    Ir(){ 
        symbol = "Ir";
        name = "Iridium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1803;
        atomicNumber = 77;
        atomicRadius = 202;
        atomicMass = 192.22f;
        ionizationenergy = 9.1f;
        electronAffinity = 1.565f; 
        electronegativity = 2.2f;
        meltingPoint = 2719;
        boilingPoint = 4701;
        density = 22.42f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 910;
        yPos = 510;
}} Ir;

static struct Pt : PeriodicTable { 
    Pt() { 
        symbol = "Pt";
        name = "Platinum";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1735;
        atomicNumber = 78;
        atomicRadius = 209;
        atomicMass = 195.08f;
        ionizationenergy = 9;
        electronAffinity = 2.128f; 
        electronegativity = 2.28f;
        meltingPoint = 2041.55;
        boilingPoint = 4098;
        density = 16.4f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1010;
        yPos = 510;
}} Pt;

static struct Au : PeriodicTable { 
    Au() { 
        symbol = "Au";
        name = "Gold";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 79;
        atomicRadius = 166;
        atomicMass = 196.96657f;
        ionizationenergy = 9.226;
        electronAffinity = 2.309f; 
        electronegativity = 2.54f;
        meltingPoint = 1337.33;
        boilingPoint = 3129;
        density = 19.282f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1110;
        yPos = 510;
}} Au;

static struct Hg : PeriodicTable { 
    Hg() { 
        symbol = "Hg";
        name = "Mercury";
        standardState = "Liquid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 80;
        atomicRadius = 209;
        atomicMass = 200.59f;
        ionizationenergy = 10.438f;
        electronegativity = 2;
        meltingPoint = 234.32;
        boilingPoint = 629.88;
        density = 13.5336f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1210;
        yPos = 510;
}} Hg;

static struct Tl : PeriodicTable { 
    Tl() { 
        symbol = "Tl";
        name = "Mercury";
        standardState = "Liquid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 1861;
        atomicNumber = 81;
        atomicRadius = 196;
        atomicMass = 204.383f;
        ionizationenergy = 6.108f;
        electronAffinity = 0.2;
        electronegativity = 1.62f;
        meltingPoint = 577;
        boilingPoint = 1746;
        density = 11.8f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1310;
        yPos = 510;
}} Tl;

static struct Pb : PeriodicTable { 
    Pb() { 
        symbol = "Pb";
        name = "Lead";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = ANCIENT;
        atomicNumber = 82;
        atomicRadius = 202;
        atomicMass = 207;
        ionizationenergy = 7.417f;
        electronAffinity = 0.36f;
        electronegativity = 2.33f;
        meltingPoint = 600.61;
        boilingPoint = 2022;
        density = 11.342f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1410;
        yPos = 510;
}} Pb;

static struct Bi : PeriodicTable { 
    Bi() { 
        symbol = "Bi";
        name = "Bismuth";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 1753;
        atomicNumber = 83;
        atomicRadius = 207;
        atomicMass = 208.98040;
        ionizationenergy = 7.289f;
        electronAffinity = 0.946f;
        electronegativity = 2.02f;
        meltingPoint = 544.55;
        boilingPoint = 1837;
        density = 9.807f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1510;
        yPos = 510;
}} Bi;

static struct Po : PeriodicTable { 
    Po() { 
        symbol = "Po";
        name = "Polonium";
        standardState = "Solid";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1898;
        atomicNumber = 84;
        atomicRadius = 197;
        atomicMass = 208.98243f;
        ionizationenergy = 8.417f;
        electronAffinity = 1.9f;
        electronegativity = 2;
        meltingPoint = 527;
        boilingPoint = 1235;
        density = 9.32f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1610;
        yPos = 510;
}} Po;

static struct At : PeriodicTable { 
    At() { 
        symbol = "At";
        name = "Astatine";
        standardState = "Halogen";
        chemicalGroupBlock = "Metalloid";
        yearDiscovered = 1940;
        atomicNumber = 85;
        atomicRadius = 202;
        atomicMass = 209.98715f;
        ionizationenergy = 9.5f;
        electronAffinity = 2.8f;
        electronegativity = 2.2f;
        meltingPoint = 575;
        density = 7;
        color = ColorGroup::METALLOID;
        xPos = 1710;
        yPos = 510;
}} At;

static struct Rn : PeriodicTable { 
    Rn() { 
        symbol = "Rn";
        name = "Radon";
        standardState = "Gas";
        chemicalGroupBlock = "Noble Gas";
        yearDiscovered = 1900;
        atomicNumber = 86;
        atomicRadius = 220;
        atomicMass = 222.01758f;
        ionizationenergy = 10.745f;
        meltingPoint = 202;
        boilingPoint = 211.45f;
        density = 0.00973;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 510;
}} Rn;

static struct Fr : PeriodicTable { 
    Fr() { 
        symbol = "Fr";
        name = "Francium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkali Metal";
        yearDiscovered = 1939;
        atomicNumber = 87;
        atomicRadius = 3455;
        atomicMass = 223.01973f;
        ionizationenergy = 3.9f;
        electronAffinity = 0.47f;
        electronegativity = 0.7f;
        meltingPoint = 202;
        color = ColorGroup::ALKALI_METAL;
        xPos = 10;
        yPos = 610;
}} Fr;

static struct Ra : PeriodicTable { 
    Ra() { 
        symbol = "Ra";
        name = "Radium";
        standardState = "Solid";
        chemicalGroupBlock = "Alkaline Earth Metal";
        yearDiscovered = 1898;
        atomicNumber = 88;
        atomicRadius = 283;
        atomicMass = 226.02541f;
        ionizationenergy = 5.279f;
        electronegativity = 0.9f;
        meltingPoint = 973;
        boilingPoint = 1413;
        density = 5;
        color = ColorGroup::ALKALINE_EARTH_METAL;
        xPos = 110;
        yPos = 610;
}} Ra;

static struct Ac : PeriodicTable { 
    Ac() { 
        symbol = "Ac";
        name = "Actinium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1899;
        atomicNumber = 89;
        atomicRadius = 260;
        atomicMass = 227.02775f;
        ionizationenergy = 5.17f;
        electronegativity = 1.1f;
        meltingPoint = 1324;
        boilingPoint = 3471;
        density = 10.07f;
        color = ColorGroup::ACTINIDE;
        xPos = 210;
        yPos = 610;
}} Ac;
 
static struct Th : PeriodicTable { 
    Th() { 
        symbol = "Th";
        name = "Thorium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1828;
        atomicNumber = 90;
        atomicRadius = 237;
        atomicMass = 232.038f;
        ionizationenergy = 6.08f;
        electronegativity = 1.3f;
        meltingPoint = 2023;
        boilingPoint = 5061;
        density = 11.72f;
        color = ColorGroup::ACTINIDE;
        xPos = 410;
        yPos = lowerBottom;
}} Th;

static struct Pa : PeriodicTable { 
    Pa() { 
        symbol = "Pa";
        name = "Protactinium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1913;
        atomicNumber = 91;
        atomicRadius = 243;
        atomicMass = 231.03588f;
        ionizationenergy = 5.89f;
        electronegativity = 1.5f;
        meltingPoint = 1845;
        density = 15.37f;
        color = ColorGroup::ACTINIDE;
        xPos = 510;
        yPos = lowerBottom;
}} Pa;

static struct U : PeriodicTable { 
    U() { 
        symbol = "U";
        name = "Uranium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1789;
        atomicNumber = 92;
        atomicRadius = 240;
        atomicMass = 238.0289f;
        ionizationenergy = 6.194f;
        electronegativity = 1.38f;
        meltingPoint = 1408;
        boilingPoint = 4404;
        density = 18.95f;
        color = ColorGroup::ACTINIDE;
        xPos = 610;
        yPos = lowerBottom;
}} U;

static struct Np : PeriodicTable { 
    Np() { 
        symbol = "Np";
        name = "Neptunium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1789;
        atomicNumber = 93;
        atomicRadius = 221;
        atomicMass = 237.048172f;
        ionizationenergy = 6.266f;
        electronegativity = 1.36f;
        meltingPoint = 917;
        boilingPoint = 4175;
        density = 20.25f;
        color = ColorGroup::ACTINIDE;
        xPos = 710;
        yPos = lowerBottom;
}} Np;

static struct Pu : PeriodicTable { 
    Pu() { 
        symbol = "Pu";
        name = "Plutonium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1940;
        atomicNumber = 94;
        atomicRadius = 243;
        atomicMass = 244.06420f;
        ionizationenergy = 6.06f;
        electronegativity = 1.28f;
        meltingPoint = 913;
        boilingPoint = 3501;
        density = 19.84f;
        color = ColorGroup::ACTINIDE;
        xPos = 810;
        yPos = lowerBottom;
}} Pu;

static struct Am : PeriodicTable { 
    Am() { 
        symbol = "Am";
        name = "Americium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1944;
        atomicNumber = 95;
        atomicRadius = 244;
        atomicMass = 243.061380f;
        ionizationenergy = 5.993f;
        electronegativity = 1.3f;
        meltingPoint = 1449;
        boilingPoint = 2284;
        density = 13.69f;
        color = ColorGroup::ACTINIDE;
        xPos = 910;
        yPos = lowerBottom;
}} Am;

static struct Cm : PeriodicTable { 
    Cm() { 
        symbol = "Cm";
        name = "Curium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1944;
        atomicNumber = 96;
        atomicRadius = 245;
        atomicMass = 247.07035f;
        ionizationenergy = 6.02f;
        electronegativity = 1.3f;
        meltingPoint = 1618;
        boilingPoint = 3400;
        density = 13.51f;
        color = ColorGroup::ACTINIDE;
        xPos = 1010;
        yPos = lowerBottom;
}} Cm;

static struct Bk : PeriodicTable { 
    Bk() { 
        symbol = "Bk";
        name = "Berkelium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1949;
        atomicNumber = 97;
        atomicRadius = 244;
        atomicMass = 247.07031f;
        ionizationenergy = 6.23f;
        electronegativity = 1.3f;
        meltingPoint = 1323;
        density = 14;
        color = ColorGroup::ACTINIDE;
        xPos = 1110;
        yPos = lowerBottom;
}} Bk;

static struct Cf : PeriodicTable { 
    Cf() { 
        symbol = "Cf";
        name = "Californium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1950;
        atomicNumber = 98;
        atomicRadius = 245;
        atomicMass = 251.07959f;
        ionizationenergy = 6.30f;
        electronegativity = 1.3f;
        meltingPoint = 1173;
        color = ColorGroup::ACTINIDE;
        xPos = 1210;
        yPos = lowerBottom;
}} Cf;

static struct Es : PeriodicTable { 
    Es() { 
        symbol = "Es";
        name = "Einsteinium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1952;
        atomicNumber = 99;
        atomicRadius = 245;
        atomicMass = 252.0830f;
        ionizationenergy = 6.42f;
        electronegativity = 1.3f;
        meltingPoint = 1133;
        color = ColorGroup::ACTINIDE;
        xPos = 1310;
        yPos = lowerBottom;
}} Es;

static struct Fm : PeriodicTable { 
    Fm() { 
        symbol = "Fm";
        name = "Fermium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1952;
        atomicNumber = 100;
        atomicMass = 257.09511f;
        ionizationenergy = 6.50f;
        electronegativity = 1.3f;
        meltingPoint = 1800;
        color = ColorGroup::ACTINIDE;
        xPos = 1410;
        yPos = lowerBottom;
}} Fm;

static struct Md : PeriodicTable { 
    Md() { 
        symbol = "Md";
        name = "Mendelevium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1955;
        atomicNumber = 101;
        atomicMass = 258.09843f;
        ionizationenergy = 6.58f;
        electronegativity = 1.3f;
        meltingPoint = 1100;
        color = ColorGroup::ACTINIDE;
        xPos = 1510;
        yPos = lowerBottom;
}} Md;

static struct No : PeriodicTable { 
    No() { 
        symbol = "No";
        name = "Nobelium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1957;
        atomicNumber = 102;
        atomicMass = 259.10100f;
        ionizationenergy = 6.65f;
        electronegativity = 1.3f;
        meltingPoint = 1100;
        color = ColorGroup::ACTINIDE;
        xPos = 1610;
        yPos = lowerBottom;
}} No;

static struct Lr : PeriodicTable { 
    Lr() { 
        symbol = "Lr";
        name = "Lawrencium";
        standardState = "Solid";
        chemicalGroupBlock = "Actinide";
        yearDiscovered = 1961;
        atomicNumber = 103;
        atomicMass = 266.120f;
        electronegativity = 1.3f;
        meltingPoint = 1900;
        color = ColorGroup::ACTINIDE;
        xPos = 1710;
        yPos = lowerBottom;
}} Lr;

static struct Rf : PeriodicTable { 
    Rf() { 
        symbol = "Rf";
        name = "Rutherfordium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1964;
        atomicNumber = 104;
        atomicMass = 267.122f;
        meltingPoint = 1964;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 410;
        yPos = 610;
}} Rf;

static struct Db : PeriodicTable { 
    Db() { 
        symbol = "Db";
        name = "Dubnium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1967;
        atomicNumber = 105;
        atomicMass = 268.126f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 510;
        yPos = 610;
}} Db;

static struct Sg : PeriodicTable { 
    Sg() { 
        symbol = "Sg";
        name = "Seaborgium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1974;
        atomicNumber = 106;
        atomicMass = 269.128f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 610;
        yPos = 610;
}} Sg;

static struct Bh : PeriodicTable { 
    Bh() { 
        symbol = "Bh";
        name = "Bohrium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1976;
        atomicNumber = 107;
        atomicMass = 270.133f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 710;
        yPos = 610;
}} Bh;

static struct Hs : PeriodicTable { 
    Hs() { 
        symbol = "Hs";
        name = "Hassiium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1984;
        atomicNumber = 108;
        atomicMass = 269.1336f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 810;
        yPos = 610;
}} Hs;

static struct Mt : PeriodicTable { 
    Mt() { 
        symbol = "Mt";
        name = "Meitnerium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1982;
        atomicNumber = 109;
        atomicMass = 277.154f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 910;
        yPos = 610;
}} Mt;

static struct Ds : PeriodicTable { 
    Ds() { 
        symbol = "Ds";
        name = "Darmstadtium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1994;
        atomicNumber = 110;
        atomicMass = 282.166f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1010;
        yPos = 610;
}} Ds;


static struct Rg : PeriodicTable { 
    Rg() { 
        symbol = "Rg";
        name = "Roentgenium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1994;
        atomicNumber = 111;
        atomicMass = 282.169f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1110;
        yPos = 610;
}} Rg;

static struct Cn : PeriodicTable { 
    Cn() { 
        symbol = "Cn";
        name = "Copernicium";
        standardState = "Solid";
        chemicalGroupBlock = "Transition Metal";
        yearDiscovered = 1996;
        atomicNumber = 112;
        atomicMass = 286.178f;
        color = ColorGroup::TRANSITION_METAL;
        xPos = 1210;
        yPos = 610;
}} Cn;

static struct Nh : PeriodicTable { 
    Nh() { 
        symbol = "Nh";
        name = "Nihonium";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 2004;
        atomicNumber = 113;
        atomicMass = 286.182f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1310;
        yPos = 610;
}} Nh;

static struct Fl : PeriodicTable { 
    Fl() { 
        symbol = "Fl";
        name = "Flerovium";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 1998;
        atomicNumber = 114;
        atomicMass = 290.192f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1410;
        yPos = 610;
}} Fl;

static struct Mc : PeriodicTable { 
    Mc() { 
        symbol = "Mc";
        name = "Moscovium";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 2003;
        atomicNumber = 115;
        atomicMass = 290.196f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1510;
        yPos = 610;
}} Mc;

static struct Lv : PeriodicTable { 
    Lv() { 
        symbol = "Lv";
        name = "Livermorium";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 2000;
        atomicNumber = 116;
        atomicMass = 293.205f;
        color = ColorGroup::POST_TRANSITION_METAL;
        xPos = 1610;
        yPos = 610;
}} Lv;

static struct Ts : PeriodicTable { 
    Ts() { 
        symbol = "Ts";
        name = "Tennessine";
        standardState = "Solid";
        chemicalGroupBlock = "Post-Transition Metal";
        yearDiscovered = 2010;
        atomicNumber = 117;
        atomicMass = 286.182f;
        color = ColorGroup::UNKNOWN_PROPERTY;
        xPos = 1710;
        yPos = 610;
}} Ts;

static struct Og : PeriodicTable { 
    Og() { 
        symbol = "Og";
        name = "Oganesson";
        standardState = "Gas";
        chemicalGroupBlock = "Noble Gas";
        yearDiscovered = 2006;
        atomicNumber = 118;
        atomicMass = 295.216f;
        color = ColorGroup::NOBLE_GAS;
        xPos = 1810;
        yPos = 610;
}} Og;

#include <iostream>
using namespace std;

class Household {
protected:
    float fuelLitres;
    float electricityUnits;

public:
    void inputData() {
        cout<<"----CARBON FOOTPRINT ESTIMATOR----\n";
        cout << "Enter total fuel consumed by your family vehicles in a month (litres): ";
        cin >> fuelLitres;

        cout << "Enter total electricity consumed in a month (units): ";
        cin >> electricityUnits;
    }
};

class CarbonCalculator : private Household {
private:
    float fuelEmission;
    float electricityEmission;
    float totalEmission;
public:
    void getInput() {
        inputData();
    }

    void calculateEmission() {
        fuelEmission = fuelLitres * 2.3;
        electricityEmission = electricityUnits * 0.82;
        totalEmission = fuelEmission + electricityEmission;
    }

    float getTotalEmission() {
        return totalEmission;
    }

    friend class Report;
};

class Report {
private:
    float targetOffset;

    // Annual CO2 absorption rates (kg/year)
    const float BAMBOO_ABSORPTION = 30.0;
    const float NEEM_ABSORPTION = 40.0;
    const float PEEPAL_ABSORPTION = 40.0;
    const float MONEY_PLANT_ABSORPTION = 10.0;

public:
    void generate(CarbonCalculator &c) {
        float emission = c.totalEmission;

        cout << "\n------ CARBON EMISSION REPORT ------\n";
        cout << "Fuel CO2 Emission        : " << c.fuelEmission << " kg\n";
        cout << "Electricity CO2 Emission : " << c.electricityEmission << " kg\n";
        cout << "TOTAL Monthly CO2        : " << emission << " kg\n";

        // Calculate yearly emissions
        float yearlyEmission = emission * 12;
        cout << "TOTAL Yearly CO2         : " << yearlyEmission << " kg\n";

        // 80% of yearly emissions to offset
        float yearlyTargetOffset = yearlyEmission * 0.8;

        cout << "\nTarget Offset (80% of yearly) : " << yearlyTargetOffset << " kg CO2/year\n";

        // Calculate total number of trees needed for the year
        int totalBambooNeeded = yearlyTargetOffset / BAMBOO_ABSORPTION;
        int totalNeemNeeded = yearlyTargetOffset / NEEM_ABSORPTION;
        int totalPeepalNeeded = yearlyTargetOffset / PEEPAL_ABSORPTION;
        int totalMoneyPlantNeeded = yearlyTargetOffset / MONEY_PLANT_ABSORPTION;

        // Add 1 to account for any remainder
        if ((int)yearlyTargetOffset % (int)BAMBOO_ABSORPTION != 0) totalBambooNeeded++;
        if ((int)yearlyTargetOffset % (int)NEEM_ABSORPTION != 0) totalNeemNeeded++;
        if ((int)yearlyTargetOffset % (int)PEEPAL_ABSORPTION != 0) totalPeepalNeeded++;
        if ((int)yearlyTargetOffset % (int)MONEY_PLANT_ABSORPTION != 0) totalMoneyPlantNeeded++;

        // Calculate trees to plant per month
        int bambooPerMonth = totalBambooNeeded / 12;
        int neemPerMonth = totalNeemNeeded / 12;
        int peepalPerMonth = totalPeepalNeeded / 12;
        int moneyPlantPerMonth = totalMoneyPlantNeeded / 12;

        // Add 1 if there's remainder
        if (totalBambooNeeded % 12 != 0) bambooPerMonth++;
        if (totalNeemNeeded % 12 != 0) neemPerMonth++;
        if (totalPeepalNeeded % 12 != 0) peepalPerMonth++;
        if (totalMoneyPlantNeeded % 12 != 0) moneyPlantPerMonth++;

        //mixed option

        float split_target = yearlyTargetOffset / 4.0;

        int mixBambooNeeded = split_target / BAMBOO_ABSORPTION;
        int mixNeemNeeded = split_target / NEEM_ABSORPTION;
        int mixPeepalNeeded = split_target / PEEPAL_ABSORPTION;
        int mixMoneyPlantNeeded = split_target / MONEY_PLANT_ABSORPTION;

        if ((int)split_target % (int)BAMBOO_ABSORPTION != 0) mixBambooNeeded++;
        if ((int)split_target % (int)NEEM_ABSORPTION != 0) mixNeemNeeded++;
        if ((int)split_target % (int)PEEPAL_ABSORPTION != 0) mixPeepalNeeded++;
        if ((int)split_target % (int)MONEY_PLANT_ABSORPTION != 0) mixMoneyPlantNeeded++;

        int mixbambooPerMonth = mixBambooNeeded / 12;
        int mixneemPerMonth = mixNeemNeeded / 12;
        int mixpeepalPerMonth = mixPeepalNeeded / 12;
        int mixmoneyPlantPerMonth = mixMoneyPlantNeeded / 12;

        if (mixBambooNeeded % 12 != 0) mixbambooPerMonth++;
        if (mixNeemNeeded % 12 != 0) mixneemPerMonth++;
        if (mixPeepalNeeded % 12 != 0) mixpeepalPerMonth++;
        if (mixMoneyPlantNeeded % 12 != 0) mixmoneyPlantPerMonth++;

        int totalmixedTrees =mixBambooNeeded + mixNeemNeeded +mixPeepalNeeded +mixMoneyPlantNeeded;

        if(emission <300) {
            cout << "\nCATEGORY : GOOD\n";
        }
        else if (emission < 600) {
            cout << "\nCATEGORY : BAD\n";
        }
        else {
            cout << "\nCATEGORY : WORST\n";
        }

        cout << "\n--- TREE PLANTING PLAN (Per Month for This Year) ---\n";
        cout << "Plant each month to offset 80% of yearly emissions:\n\n";

        cout << "OPTION 1: " << bambooPerMonth << " Bamboo plants/month";
        cout << " (Total: " << totalBambooNeeded << " trees by year end)\n";

        cout << "OPTION 2: " << neemPerMonth << " Neem trees/month";
        cout << " (Total: " << totalNeemNeeded << " trees by year end)\n";

        cout << "OPTION 3: " << peepalPerMonth << " Peepal trees/month";
        cout << " (Total: " << totalPeepalNeeded << " trees by year end)\n";

        cout << "OPTION 4: " << moneyPlantPerMonth << " Money plants/month";
        cout << " (Total: " << totalMoneyPlantNeeded << " plants by year end)\n";

        cout<<"---------MIXED OPTION---------\n";

        cout << mixbambooPerMonth << " Bamboo plants/month";
        cout << " (Total: " << mixBambooNeeded << " trees by year end)\n";

        cout << mixneemPerMonth << " Neem trees/month";
        cout << " (Total: " << mixNeemNeeded << " trees by year end)\n";

        cout << mixpeepalPerMonth << " Peepal trees/month";
        cout << " (Total: " << mixPeepalNeeded << " trees by year end)\n";

        cout << mixmoneyPlantPerMonth << " Money plants/month";
        cout << " (Total: " << mixMoneyPlantNeeded << " plants by year end)\n";

        cout << "You will plant "<<totalmixedTrees <<" trees in total.";

        cout << "\n--- FUTURE SUGGESTIONS ---\n";
        cout << "- Reduce unnecessary vehicle usage\n";
        cout << "- Use LED lights & energy-efficient appliances\n";
        cout << "- Prefer public transport\n";
        cout << "- Increase rooftop or balcony plants\n";
    }
};

int main() {
    CarbonCalculator calculator;
    Report report;

    calculator.getInput();
    calculator.calculateEmission();
    report.generate(calculator);

    return 0;
}

🌍 Carbon Footprint Estimator (C++)

A simple C++ console application that estimates a household’s carbon footprint based on monthly fuel and electricity consumption, and then generates a tree-planting plan to offset 80% of yearly CO₂ emissions.

This project demonstrates:

Object-Oriented Programming (OOP)

Inheritance & Access Specifiers

Friend classes

Real-world problem solving using C++

✨ Features

📊 Calculates:

Fuel CO₂ emissions

Electricity CO₂ emissions

Total monthly & yearly CO₂ emissions

🌱 Categorizes impact:

GOOD, BAD, or WORST based on emissions

🌳 Suggests tree plantation plans:

Bamboo

Neem

Peepal

Money Plant

🔀 Also provides a Mixed Plantation Option

📅 Shows:

Total trees needed per year

Trees to plant per month

💡 Gives future suggestions to reduce carbon footprint

🧮 Emission Calculation Logic

Fuel CO₂ = fuelLitres × 2.3 kg

Electricity CO₂ = electricityUnits × 0.82 kg

Total Monthly CO₂ = Fuel + Electricity

Yearly CO₂ = Monthly × 12

Target Offset = 80% of Yearly CO₂

Tree absorption assumptions (kg CO₂ / year):

🌿 Bamboo: 30

🌳 Neem: 40

🌳 Peepal: 40

🍀 Money Plant: 10

🏗️ Project Structure

Household
→ Takes input for fuel and electricity usage

CarbonCalculator (inherits from Household)
→ Calculates emissions

Report (friend class of CarbonCalculator)
→ Generates detailed report and plantation plan

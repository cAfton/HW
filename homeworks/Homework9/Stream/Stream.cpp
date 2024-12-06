1#include "Handbook.h"

int main()
{
	Handbook hand;
    hand.addNew(Company("Tech Solutions", "John Smith", 38012321001, "123 Tech Lane", "IT Services"));
    hand.addNew(Company("Green Energy Co", "Emma Wilson", 38012321002, "45 Solar St", "Renewable Energy"));
    hand.addNew(Company("Auto Galaxy", "Michael Brown", 38012321003, "78 Car Drive", "Automotive"));
    hand.addNew(Company("Health Plus", "Sophia Taylor", 38012321004, "22 Wellness Blvd", "Healthcare"));
    hand.addNew(Company("EduSmart", "Liam Johnson", 38012321005, "16 Learning Ave", "Education"));
    hand.addNew(Company("Foodies Delight", "Olivia Martinez", 38012321006, "89 Flavor Road", "Food and Beverage"));
    hand.addNew(Company("Pixel Art Studio", "Ethan Davis", 38012321007, "5 Design Way", "Graphic Design"));
    hand.addNew(Company("Home Builders Inc", "Isabella Moore", 38012321008, "12 Build Court", "Construction"));
    hand.addNew(Company("Travel Bliss", "James White", 38012321009, "34 Wander St", "Tourism"));
    hand.addNew(Company("Fashion Forward", "Ava Anderson", 38012321010, "67 Style Lane", "Fashion and Apparel"));
    

    cout << hand.findByName("Auto Galaxy").getCompanyName() << endl;
    cout << hand.findByDirector("Ethan Davis").getCompanyName() << endl;
    cout << hand.findByNumber(38012321010).getCompanyName() << endl;
    cout << hand.findByActivity("Tourism").getCompanyName() << endl;
}
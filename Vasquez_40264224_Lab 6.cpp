#include <iostream>
#include <string>
#include "EV.h"

using namespace std;

EV::EV(int range, int year) : range_(range), year_(year) {}

EV::EV(int range, int year, const std::string& model, const std::string& unit) : range_(range), year_(year), model_(model), unit_(unit) {}

void EV::getmodel(std::string model) {
    model_ = model;
}

void EV::getunit(std::string unit) {
    unit_ = unit;
}

void EV::getrange(int range) {
    range_ = range;
}

void EV::getyear(int year) {
    year_ = year;
}

std::string EV::getmodel() const {
    return model_;
}

std::string EV::getunit() const {
    return unit_;
}

int EV::getrange() const {
    return range_;
}

int EV::getyear() const {
    return year_;
}

void EV::info() const {
    cout << "The EV " << getmodel() << " manufactured in " << getyear() << " has a range of " << range_ << " " << unit_ << endl;
}

double EV::Convert(std::string unit) const {
    if (unit == "miles") {
        return range_ * 1.60934;
    }
    else {
        return range_;
    }
}

void EV::Compare(EV* ev) {
    double this_range, ev_range;
    if (this->unit_ == "kilometers") {
        this_range = this->Convert("miles");
    }
    else {
        this_range = this->range_;
    }
    if (ev->unit_ == "kilometers") {
        ev_range = ev->Convert("miles");
    }
    else {
        ev_range = ev->range_;
    }

    if (this_range < ev_range) {
        cout << "drives longer distance on a single charge than" << endl;
    }
    else if (this_range > ev_range) {
        cout << "drives shorter distance on a single charge than" << endl;
    }
    else {
        cout << "drives the same distance on a single charge as" << endl;
    }
}

using namespace std;


int main() {
    string model1, unit1;
    string model2, unit2;
    int range1, year1;
    int range2, year2;

    cout << "Load first EV" << endl;
    cout << "Enter EV Model: ";
    getline(cin, model1);
    cout << "Enter year manufactured: ";
    cin >> year1;
    cout << "Enter range unit (miles or kilometers): ";
    cin >> unit1;
    cout << "You choose " << unit1 << ", so please enter range in " << unit1 << ": ";
    cin >> range1;

    EV* ev1 = new EV(range1, year1, model1, unit1);
    cout << endl;
    cout << "Load second EV" << endl;
    cout << "Enter EV Model: ";
    cin.ignore(); // clear input buffer
    getline(cin, model2);
    cout << "Enter year manufactured: ";
    cin >> year2;
    cout << "Enter range unit (miles or kilometers): ";
    cin >> unit2;
    cout << "You choose " << unit2 << ", so please enter range in " << unit2 << ": ";
    cin >> range2;

    EV* ev2 = new EV(range2, year2, model2, unit2);
    cout << endl;
    ev1->info();
    ev1->Compare(ev2);
    ev2->info();

    delete ev1;
    delete ev2;
    return 0;
}
#ifndef ANALYZER_EVER_ARMED_H
#define ANALYZER_EVER_ARMED_H

/*
 * analyzer_ever_armed
 *
 */

#include "analyzer.h"

class Analyzer_Ever_Armed_Result : public Analyzer_Result_Summary {
public:
    Analyzer_Ever_Armed_Result() :
        Analyzer_Result_Summary()
        { }

    void set_arm_time(uint64_t timestamp) { _arm_time = timestamp; }
    uint64_t arm_time() const { return _arm_time; }

    void to_json(Json::Value &root) const override;

private:
    uint64_t _arm_time;
};

class Analyzer_Ever_Armed : public Analyzer {

public:
    Analyzer_Ever_Armed(AnalyzerVehicle::Base *&vehicle) :
	Analyzer(vehicle)
    { }

    bool configure(INIReader *config);

    const char *name() const override { return "Ever Armed"; }
    const char *description() const override {
        return "This test will FAIL if the craft never armed during the log";
    }

    void evaluate() override;
    void end_of_log(const uint32_t packet_count) override;

private:
    Analyzer_Ever_Armed_Result _result;
};

#endif

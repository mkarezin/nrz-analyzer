#ifndef NRZ_SIMULATION_DATA_GENERATOR
#define NRZ_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class NRZAnalyzerSettings;

class NRZSimulationDataGenerator
{
public:
	NRZSimulationDataGenerator();
	~NRZSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, NRZAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	NRZAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //NRZ_SIMULATION_DATA_GENERATOR
#ifndef NRZ_ANALYZER_H
#define NRZ_ANALYZER_H

#include <Analyzer.h>
#include "NRZAnalyzerResults.h"
#include "NRZSimulationDataGenerator.h"

class NRZAnalyzerSettings;
class ANALYZER_EXPORT NRZAnalyzer : public Analyzer2
{
public:
	NRZAnalyzer();
	virtual ~NRZAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< NRZAnalyzerSettings > mSettings;
	std::auto_ptr< NRZAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	NRZSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //NRZ_ANALYZER_H

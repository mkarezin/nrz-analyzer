#ifndef NRZ_ANALYZER_SETTINGS
#define NRZ_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

class NRZAnalyzerSettings : public AnalyzerSettings
{
public:
	NRZAnalyzerSettings();
	virtual ~NRZAnalyzerSettings();

	virtual bool SetSettingsFromInterfaces();
	void UpdateInterfacesFromSettings();
	virtual void LoadSettings( const char* settings );
	virtual const char* SaveSettings();

	
	Channel mInputChannel;
	U32 mBitRate;

protected:
	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mInputChannelInterface;
	std::auto_ptr< AnalyzerSettingInterfaceInteger >	mBitRateInterface;
};

#endif //NRZ_ANALYZER_SETTINGS

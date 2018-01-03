Pod::Spec.new do |s|
  s.name             = 'dach-mguSdk-iOS'
  s.version          = '2.2.0'
  s.summary          = 'VerveWireless (Matchinguu) SDK for iOS'
  s.license          = { :type => 'Commercial' , :file => 'Licenses/Matchingg-LICENSE.txt'}
  s.description      = 'Matchinguu provides a round trip environment for location/context based services. In general a context based service manages the current user
location in relation to any other available context like known POIs (Point of Interest), user behavior and the app specific context like profile
information.'
  s.homepage = 'http://www.matchinguu.com/'
  s.author           = { 'Matchinguu' => 'mohammed.fathy@verve.com' }
  s.source           = { :git => 'https://github.com/VerveWireless/dach-mguSdk-iOS.git', :tag => s.version.to_s }
  s.platforms   = { :ios => "7.0"}
  s.default_subspec = 'mguSdk'
  s.libraries = 'c++'
  s.frameworks = 'CoreLocation' , 'AudioToolBox' , 'AdSupport' , 'CoreTelephony'

  s.subspec 'mguSdk' do |ss|
    ss.source_files = [
      'mguSdk/include/MguSDK/MguSDK.h'
    ]

    ss.platform   = :ios, '7.0'
    ss.vendored_libraries = "mguSdk/libMguSDK.a"
  end
end

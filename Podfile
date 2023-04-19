# Uncomment the next line to define a global platform for your project
platform :ios, '13.0'

target 'MapsIndoorsGettingStarted-Mapbox' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

 # Pods for MapsIndoorsGettingStarted-Google
  pod 'MapsIndoorsMapbox', '~> 4.0.2'
end

PROJECT_ROOT_DIR = File.dirname(File.expand_path(__FILE__))
PODS_DIR = File.join(PROJECT_ROOT_DIR, 'Pods')
PODS_TARGET_SUPPORT_FILES_DIR = File.join(PODS_DIR, 'Target Support Files')

post_install do |pi|

  pi.pods_project.targets.each do |t|
    t.build_configurations.each do |bc|
      bc.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '13.0'
      bc.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
    end
  end


end



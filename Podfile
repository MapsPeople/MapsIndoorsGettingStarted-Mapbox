# Uncomment the next line to define a global platform for your project
platform :ios, '13.0'

target 'MapsIndoorsGettingStarted-Mapbox' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

 # Pods for MapsIndoorsGettingStarted-Google
  pod 'MapsIndoorsMapbox', '~> 4.0.2'
end
post_install do |pi|
  pi.pods_project.targets.each do |t|
    t.build_configurations.each do |bc|
      bc.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
    end
  end
end

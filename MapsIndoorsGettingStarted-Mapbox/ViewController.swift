//  ViewController.swift
import UIKit
import MapsIndoorsCore
import MapsIndoorsMapbox
import MapboxMaps

class ViewController: UIViewController {
    
    var mapView: MapView!
    var mapConfig: MPMapConfig?
    var mapControl: MPMapControl?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Set up the Mapbox map view
        let mapInitOptions = MapInitOptions(resourceOptions: ResourceOptions(accessToken: AppDelegate.mApiKey))
        mapView = MapView(frame: view.bounds, mapInitOptions: mapInitOptions)
        view.addSubview(mapView)

        // Set up the autoresizing mask to keep the map's frame synced with the view controller's frame.
        mapView.autoresizingMask = [.flexibleWidth, .flexibleHeight]

        // Center the map on a specific location
        let centerCoordinate = CLLocationCoordinate2D(latitude: 38.8977, longitude: -77.0365)
        mapView.mapboxMap.setCamera(to: CameraOptions(center: centerCoordinate, zoom: 20))

        // Initialize the MPMapConfig with the Mapbox MapView
        mapConfig = MPMapConfig(mapBoxView: mapView, accessToken: AppDelegate.mapBoxApiKey!)
        
        // Initialize the MPMapControl with the MPMapConfig.
        Task {
            // Load MapsIndoors with the MapsIndoors API key.
            try await MPMapsIndoors.shared.load(apiKey: AppDelegate.mApiKey)
            if let mapConfig = mapConfig {
                mapControl = MPMapsIndoors.createMapControl(mapConfig: mapConfig)
                // further set up SDK.
                // ...
            }
        }
    }
}

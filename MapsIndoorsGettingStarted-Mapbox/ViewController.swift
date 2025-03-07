import MapboxMaps
import MapsIndoorsCore
import MapsIndoorsMapbox
import UIKit

class ViewController: UIViewController {

    var mapView: MapView!
    var mapControl: MPMapControl?

    override func viewDidLoad() {
        super.viewDidLoad()
        setupMapboxView()

        Task {
            do {
                // Load MapsIndoors with the MapsIndoors API key.
                try await MPMapsIndoors.shared.load(apiKey: AppDelegate.mApiKey)

                // Initialize the MPMapConfig with the Mapbox map view. A MPMapConfig is needed to initialise a MPMapsIndoors map control – to interact with the map.
                let mapConfig = MPMapConfig(mapBoxView: mapView, accessToken: "mapBoxApiKey")
                mapConfig.setShowRoadLabels(show: false)
                mapConfig.setMapsIndoorsTransitionLevel(zoom: 16)
                if let mapControl = MPMapsIndoors.createMapControl(mapConfig: mapConfig) {
                    // Retain the mapControl object, or lose the ability to interact with the map
                    self.mapControl = mapControl

                    // Create a query to locate a specific Location
                    let query = MPQuery()
                    let filter = MPFilter()

                    query.query = "The Crow"
                    filter.take = 1

                    let locations = await MPMapsIndoors.shared.locationsWith(query: query, filter: filter)
                    if let firstLocation = locations.first {
                        mapControl.goTo(entity: firstLocation)
                        mapControl.select(location: firstLocation, behavior: .default)
                        // Set the origin for directions to "The Crow" meeting room
                        origin = firstLocation
                    }
                }
            } catch {
                print("Error loading MapsIndoors: \(error.localizedDescription)")
            }
        }

        // Set up UI for search bar, table view for search results, and buttons to toggle live data
        ExampleUI.create(parentView: view, searchDelegate: self)
        tableView.dataSource = self
        tableView.delegate = self
    }

    // Get directions to the selected search result
    func directions(to destination: MPLocation) {
        let directionsQuery = MPDirectionsQuery(origin: origin!, destination: destination)

        Task {
            do {
                let route = try await MPMapsIndoors.shared.directionsService.routingWith(query: directionsQuery)
                directionsRenderer?.route = route
                directionsRenderer?.routeLegIndex = 0
                directionsRenderer?.animate(duration: 5)
            } catch {
                print("Error getting directions: \(error.localizedDescription)")
            }
        }
    }

    // Add the renderer property and origin point (populated when map shows, for demo purpose)
    lazy var directionsRenderer: MPDirectionsRenderer? = {
        mapControl?.newDirectionsRenderer()
    }()
    var origin: MPLocation?

    private func setupMapboxView() {
        // Set up the Mapbox map view
        let options = MapInitOptions()
        mapView = MapView(frame: view.bounds, mapInitOptions: options)
        view.addSubview(mapView)

        // Set up the autoresizing mask to keep the map's frame synced with the view controller's frame.
        mapView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
    }

    var searchResult: [MPLocation]?
    lazy var tableView = UITableView(frame: CGRect(x: 0, y: 90, width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height))

    var isLivePositionEnabled = false
    var isLiveOccupancyEnabled = false

}

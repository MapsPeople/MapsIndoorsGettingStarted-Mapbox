import Foundation
#if canImport(FoundationNetworking)
import FoundationNetworking
#endif

/**
 An error that occurs when calculating isochrone contours.
 */
public enum IsochroneError: LocalizedError {
    
    public init(code: String?, message: String?, response: URLResponse?, underlyingError error: Error?) {
        if let response = response as? HTTPURLResponse {
            switch (response.statusCode, code ?? "") {
            case (200, "NoSegment"):
                self = .unableToLocate
            case (404, "ProfileNotFound"):
                self = .profileNotFound
            case (422, "InvalidInput"):
                self = .invalidInput(message: message)
            case (429, _):
                self = .rateLimited(rateLimitInterval: response.rateLimitInterval, rateLimit: response.rateLimit, resetTime: response.rateLimitResetTime)
            default:
                self = .unknown(response: response, underlying: error, code: code, message: message)
            }
        } else {
            self = .unknown(response: response, underlying: error, code: code, message: message)
        }
    }
    
    /**
     There is no network connection available to perform the network request.
     */
    case network(_: URLError)
    
    /**
     The server returned a response that isn’t correctly formatted.
     */
    case invalidResponse(_: URLResponse?)
    
    /**
     The server returned an empty response.
     */
    case noData
    
    /**
     A specified location could not be associated with a roadway or pathway.
     
     Make sure the locations are close enough to a roadway or pathway.
     */
    case unableToLocate
    
    /**
     Unrecognized profile identifier.
     
     Make sure the `IsochroneOptions.profileIdentifier` option is set to one of the predefined values, such as `IsochroneProfileIdentifier.automobile`.
     */
    case profileNotFound
    
    /**
    The API recieved input that it didn't understand.
     */
    case invalidInput(message: String?)
    
    /**
     Too many requests have been made with the same access token within a certain period of time.
     
     Wait before retrying.
     */
    case rateLimited(rateLimitInterval: TimeInterval?, rateLimit: UInt?, resetTime: Date?)
    
    /**
     Unknown error case. Look at associated values for more details.
     */
    case unknown(response: URLResponse?, underlying: Error?, code: String?, message: String?)
}

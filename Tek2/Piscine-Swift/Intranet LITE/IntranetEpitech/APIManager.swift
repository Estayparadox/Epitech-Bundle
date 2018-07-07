//
//  APIManager.swift
//  IntranetEpitech
//
//  Created by Joseph Pereniguez on 25/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit
import Alamofire
import Kingfisher
import SwiftyJSON
import PageController
import TVButton

class APIManager: NSObject {

    let url = "http://epitech-api.herokuapp.com"
    static let instanceShared = APIManager()
    private var token : String?
    
    func getLogin(login: String, password: String, completionHandler: (json:JSON)-> Void){
        Alamofire.request(.POST, url + "/login", parameters: ["login": login, "password": password])
            .responseJSON { response in
            let json = JSON(data: response.data!)
                if let token = json["token"].string {
                    self.token = token
                }
                completionHandler(json: json)
        }
    }

    func getUser(login: String, completionHandler: (json:JSON)-> Void){
        Alamofire.request(.GET, url + "/user", parameters: ["token": token!, "user": login])
            .responseJSON { response in
            let json = JSON(data: response.data!)
            completionHandler(json: json)
        }
    }

}
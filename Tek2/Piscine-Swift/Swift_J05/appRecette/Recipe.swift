//
//  Recipe.swift
//  appRecette
//
//  Created by Joseph Pereniguez on 23/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import Foundation

class Recipe {
    
    var aName: String
    var anImage: String
    var aTime: String
    
    init (Name: String, Image: String, Time: String) {
        self.aName = Name
        self.anImage = Image
        self.aTime = Time
    }

}
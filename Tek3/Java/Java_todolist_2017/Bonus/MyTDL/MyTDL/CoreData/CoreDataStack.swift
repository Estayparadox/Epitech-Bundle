//
//  CoreDataStack.swift
//  MyTDL
//
//  Created by Joseph Pereniguez on 04/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import Foundation
import CoreData

class CoreDataStack {
    var container: NSPersistentContainer {
        let container = NSPersistentContainer(name: "Todos")
        container.loadPersistentStores { (description, error) in
            guard error == nil else {
                print("Error: \(error!)")
                return
            }
        }
        
        return container
    }
    
    var manageContext: NSManagedObjectContext {
        return container.viewContext
    }
}

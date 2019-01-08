//
//  ProjectCell.swift
//  ToDoList
//
//  Created by Joseph Pereniguez on 26/02/2018.
//  Copyright © 2018 Joseph Pereniguez. All rights reserved.
//

import UIKit

class ProjectCell: UITableViewCell {

    // MARK: Outlets
    
    @IBOutlet weak var projectName: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}

//
//  CustumCell.swift
//  tuto2
//
//  Created by Joseph Pereniguez on 22/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit

class CustumCell: UITableViewCell {

    @IBOutlet weak var status: UILabel!
 
    @IBOutlet weak var check: UISwitch!
    
    @IBOutlet weak var myLabel: UILabel!
    
    @IBAction func activator(sender: AnyObject) {
        if check.on {
           status.text = "Ouverte"
            status.textColor = UIColor.greenColor()
        }
        else {
            status.text = "Fermée"
            status.textColor = UIColor.redColor()
        }
    }
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    
}

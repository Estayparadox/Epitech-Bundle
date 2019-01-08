//
//  myCell.swift
//  appRecette
//
//  Created by Joseph Pereniguez on 23/03/2016.
//  Copyright © 2016 Joseph Pereniguez. All rights reserved.
//

import UIKit

class myCell: UITableViewCell {
    
    @IBOutlet weak var nameOfRecipe: UILabel!
    
    @IBOutlet weak var imageOfRecipe: UIImageView!
    
    @IBOutlet weak var time: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
    func createCell(_ myRecipe: Recipe){
        self.nameOfRecipe.text = myRecipe.aName
        self.imageOfRecipe.image = UIImage(named: myRecipe.anImage)
        self.time.text = myRecipe.aTime
    }

}

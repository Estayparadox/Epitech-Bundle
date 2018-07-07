//
//  WHRoundedImageView.swift
//  WHRoundedImageView
//
//  Created by Wei He <whe@weispot.com> on 5/22/15.
//  Copyright (c) 2015 Wei He. All rights reserved.
//

import Foundation

@IBDesignable public class WHRoundedImageView: UIImageView {
    
    
    // MARK: - Properties
    
    @IBInspectable public var radiusRatio: CGFloat = 0.0 {
        didSet {
            self.layer.cornerRadius = self.bounds.size.width * radiusRatio
        }
    }
    
    @IBInspectable public var borderWidth: CGFloat = 0.0 {
        didSet {
            self.layer.borderWidth = borderWidth
        }
    }
    
    @IBInspectable public var borderColor: UIColor = UIColor.blackColor() {
        didSet {
            self.layer.borderColor = borderColor.CGColor
        }
    }
    
    
    // MARK: - Constructors
    
    required public init(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)!
        setup()
    }
    
    override public init(frame: CGRect) {
        super.init(frame: frame)
        setup()
    }
    
    override public init(image: UIImage!) {
        super.init(image: image)
        setup()
    }
    
    override public init(image: UIImage!, highlightedImage: UIImage?) {
        super.init(image: image, highlightedImage: highlightedImage)
        setup()
    }
    
    
    // MARK: - Support Methods
    
    func setup() {
        self.layer.masksToBounds = true
    }
    
    override public func prepareForInterfaceBuilder() {
        setup()
    }
}

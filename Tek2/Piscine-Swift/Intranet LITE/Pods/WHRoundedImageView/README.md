# WHRoundedImageView ![WHRoundedImageView](https://img.shields.io/cocoapods/v/WHRoundedImageView.svg) ![WHRoundedImageView](https://img.shields.io/cocoapods/l/WHRoundedImageView.svg) ![WHRoundedImageView](https://img.shields.io/cocoapods/p/WHRoundedImageView.svg) [![Analytics](https://ga-beacon.appspot.com/UA-63284043-1/WHRoundedImageView/README.md?pixel)](https://github.com/ddhhz/WHRoundedImageView)

WHRoundedImageView is a plain simple _swift_ component that extends a UIImageView. It allows you to add Radius and Border to an image directly in Interface Builder.

*Live preview is fully supported.*

![WHRoundedImageView](WHRoundedImageViewDemo.gif "WHRoundedImageView")

## Installation
##### *For iOS 8.0+*
RoundImageView is available through CocoaPods, just add the reference to your Podfile:

```
pod 'WHRoundedImageView'
```

##### *For All* (including iOS 8.0+)
You can copy ```WHRoundedImageView.swift``` directly into your project.

## Usage
1. Set class to ```WHRoundedImageView``` in _Identity Inspector_, and use it as a normal UIImageView. 
2. Set properties below:
    - ```radiusRatio```  _Default: 0.0_ (0.5 = fully rounded corners for square images)
    - ```borderWidth```  _Default: 0.0_
    - ```borderColor```  _Default: blackColor_

## Author
**Wei He** _whe@weispot.com_

## Credits
Fork of [ravero/RoundImageView](https://github.com/ravero/RoundImageView)

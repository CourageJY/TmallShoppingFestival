cmake_minimum_required(VERSION 3.15)
project(TmallShoppingFestival)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

include_directories(Codes/AfterSale)
include_directories(Codes/Filter)
include_directories(Codes/Mediator)
include_directories(Codes/Order)
include_directories(Codes/Page)
include_directories(Codes/PersonalInformation)
include_directories(Codes/Shop)
include_directories(Codes/ShoppingCart)
include_directories(Codes/User)
include_directories(Codes/Venue)

add_executable(TmallShoppingFestival
        Codes/AfterSale/AfterSale.cpp
        Codes/AfterSale/AfterSale.h
        Codes/AfterSale/makeComment.h
        Codes/Filter/filter.cpp
        Codes/Filter/filter.h
        Codes/Mediator/mediator.cpp
        Codes/Mediator/mediator.h
        Codes/Order/balance.cpp
        Codes/Order/balance.h
        Codes/Order/checkOrder.cpp
        Codes/Order/checkOrder.h
        Codes/Order/order.cpp
        Codes/Order/order.h
        Codes/Order/orderState.cpp
        Codes/Order/orderState.h
        Codes/Order/payment.cpp
        Codes/Order/payment.h
        Codes/Page/page.cpp
        Codes/Page/page.h
        Codes/PersonalInformation/Comment.cpp
        Codes/PersonalInformation/Comment.h
        Codes/PersonalInformation/customer.cpp
        Codes/PersonalInformation/customer.h
        Codes/PersonalInformation/SearchEngine.cpp
        Codes/PersonalInformation/SearchEngine.h
        Codes/Shop/brand.h
        Codes/Shop/clothingGoodsFactory.h
        Codes/Shop/commentList.h
        Codes/Shop/coupon.cpp
        Codes/Shop/coupon.h
        Codes/Shop/goods.cpp
        Codes/Shop/goods.h
        Codes/Shop/phoneBuilder.h
        Codes/Shop/shop.cpp
        Codes/Shop/shop.h
        Codes/ShoppingCart/shoppingCart.cpp
        Codes/ShoppingCart/shoppingCart.h
        Codes/User/user.cpp
        Codes/User/user.h
        Codes/User/userSet.cpp
        Codes/Venue/venue.cpp
        Codes/Venue/venue.h
        Codes/tools.h
        Codes/main.cpp)

macro(find  _feature)
    find_feature(${_feature} ${${_feature}_FEATURE_TYPE} ${${_feature}_FEATURE_PURPOSE} ${${_feature}_FEATURE_DESCRIPTION})
endmacro(find)

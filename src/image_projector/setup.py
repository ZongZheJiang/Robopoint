from setuptools import find_packages, setup

package_name = 'image_projector'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
    ],
    install_requires=['setuptools','robopoint_interfaces'],
    zip_safe=True,
    maintainer='ddq2',
    maintainer_email='hominhan56@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'service = image_projector.image_projector:main'
        ],
    },
)
